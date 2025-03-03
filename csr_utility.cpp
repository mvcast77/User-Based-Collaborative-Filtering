#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <typeinfo>
#include "csr_utility.h"

//template struct CSR<int>;
template struct CSR<double>;
template std::vector<double> operator*(const CSR<double>*, const std::vector<double>&);
template std::vector<int> operator*(const CSR<int>*, const std::vector<int>&);
//template void CSR::operator*=(const int coefficient);
//template void CSR::operator*=(const double coefficient);
template CSR<double>* transpose(CSR<double>*, CSR<double>*);
template std::istream& operator>>(std::istream&, CSR<int>*);
template std::istream& operator>>(std::istream&, CSR<double>*);
template std::ostream& operator<<(std::ostream&, const CSR<double>*);
template std::ostream& operator<<(std::ostream&, const CSR<int>*);

template <typename T>
std::vector<T> CSR<T>::cosine(const std::vector<T>& x) const{
	int spot = 0, count = 0;
	T sum = 0;
	std::vector<T> result;
	std::vector<bool> flags;

	for (int i = 0; i < ptr.size() - 1; ++i){
		sum = count = 0;
		for (int j = 0; count < ptr[i+1] - ptr[i]; ++j){
			flags.push_back(false);
			if (j == indices[spot]){
				if (x[j] == 0){
					sum += x[j] * values[spot];
					flags[j] = true;
				}
				++spot; ++count;
			}

			flags.clear();
		}
		result.push_back(sum);
	}
	return result;
}

template <typename T>
std::vector<T> CSR<T>::vector_mult(const std::vector<T>& x) const{
	int spot = 0, count = 0;
	T sum = 0;
	std::vector<T> result;

	for (int i = 0; i < ptr.size() - 1; ++i){
		sum = count = 0;
		for (int j = 0; count < ptr[i+1] - ptr[i]; ++j){
			if (j == indices[spot]){
				sum += x[j] * values[spot];
				++spot; ++count;
			}
		}
		result.push_back(sum);
	}
	return result;
}

template <typename T>
std::vector<T> operator*(const CSR<T>* csr, const std::vector<T>& x){
	return csr->vector_mult(x);
}

template <typename T>
void CSR<T>::operator*=(const T coefficient){
	for (auto& value : this->values)
		value = value * coefficient;
	//return csr;
}

template <typename T>
CSR<T>* transpose(CSR<T>* old, CSR<T>* newby){
    //CSR<T> newby;
    newby->columns = old->ptr.size() - 1;

    for (int i = 0; i < old->columns + 1; ++i)
        newby->ptr.push_back(0);
        
    for (const auto& ind : old->indices){
        newby->ptr[ind + 1]++;
        newby->values.push_back(0);
        newby->indices.push_back(0);
	}
        
    for (int i = 1; i < old->columns + 1; ++i)
        newby->ptr[i] += newby->ptr[i-1];
    newby->ptr[0] = 0;
        
    auto temp = newby->ptr;
    
    T v,c = 0;
    for(int i = 0; i < old->ptr.size() - 1; ++i){
     for(int j = old->ptr[i]; j < old->ptr[i + 1]; ++j){
        v = old->values[j];
        c = old->indices[j];
        newby->indices[temp[c]] = i;
        newby->values[temp[c]] = v;
        temp[c]++;
     }
    }
    
    return newby;
}


template <typename T>
std::istream& operator>>(std::istream& file, CSR<T>* csr){

	unsigned first_num;
	unsigned second_num;
	unsigned third_num;
	unsigned current = 0;
	//unsigned count;
	unsigned max_col = 0;

	csr->ptr.push_back(0);
	while (file >> first_num){
		while (first_num > current){
			++current;
			csr->ptr.push_back(0);
		}
		file >> second_num >> third_num;
		if (second_num > max_col) max_col = second_num;

		csr->indices.push_back(second_num);
		csr->values.push_back(third_num);

		csr->ptr[current]++;
	}
	//adjusting ptr to contains entry numbers, as per requirement
	for (int i = 1; i < csr->ptr.size(); ++ i) csr->ptr[i] += csr->ptr[i-1];

	csr->columns = max_col + 1;

	return file;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const CSR<T>* csr){
	os << "[";
	for (const auto& val : csr->values) os << val << ", ";
	os << "]\n";
	os << "[";
	for (const auto& ind : csr->indices) os << ind << ", ";
	os << "]\n";
	os << "[";
	for (const auto& pts : csr->ptr) os << pts << ", ";
	os << "]\n";

	return os;
}
