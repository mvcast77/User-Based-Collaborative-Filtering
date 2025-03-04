#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>
#include "vector_utility.h"

template std::vector<int> operator+(const std::vector<int>&, const std::vector<int>&);
template std::vector<double> operator+(const std::vector<double>&, const std::vector<double>&);
template std::vector<int> operator-(const std::vector<int>&, const std::vector<int>&);
template std::vector<double> operator-(const std::vector<double>&, const std::vector<double>&);
template std::vector<double> teleport(const double, const int);
template std::istream& operator>>(std::istream& file, std::vector<std::pair<unsigned,int>>& vec);
template std::istream& operator>>(std::istream& file, std::vector<std::pair<unsigned,double>>& vec);
template std::ostream& operator<<(std::ostream&, const std::vector<double>&);
template std::ostream& operator<<(std::ostream&, const std::vector<int>&);
template double magnitude(const std::vector<double>);
template bool second_item(const std::pair<unsigned,int>&, const std::pair<unsigned,int>&);

template <typename T>
std::istream& operator>>(std::istream& file, std::vector<std::pair<unsigned,T>>& vec){

	unsigned first_num;
	unsigned second_num;
	unsigned third_num;
	unsigned current;
	file >> current >> second_num >> third_num;
	vec.push_back({second_num, third_num});

	while (file >> first_num && first_num == current){
		file >> second_num >> third_num;
		vec.push_back({second_num, third_num});
	}
	file.unget();
	file.unget();
	file.unget();

	return file;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec){
	os.precision(10);
	os << std::scientific;
	for (const auto& val : vec)
		os << val << "\n";
	return os;
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b){
	std::vector<T> result;

	int b_ind = 0;
	for (const auto& val : a){
		result.push_back(val + b[b_ind]);
		++b_ind;
	}

	return result;
}

template <typename T>
std::vector<T> operator-(const std::vector<T>& a, const std::vector<T>& b){
	std::vector<T> result;

	int b_ind = 0;
	for (const auto& val : a){
		result.push_back(val - b[b_ind]);
		++b_ind;
	}

	return result;
}

template <typename T>
std::vector<T> teleport(const T d, const int total){
	T not_d = 1 - d;
	T not_d_N = not_d / total;

	std::vector<T> tele_identity;
	for (int i = 0; i < total; ++i)
		tele_identity.push_back(not_d_N);
	return tele_identity;
}

template <typename T>
T magnitude(const std::vector<T> vec){
	T magnit = 0;
	for (const auto& val : vec)
		magnit += (val * val);
	magnit = sqrt(magnit);
	return magnit;
}

template <typename A, typename B>
bool second_item(const std::pair<A,B>& left, const std::pair<A,B>& right){
	return (left.second > right.second);
}
