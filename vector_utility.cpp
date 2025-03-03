#include <cstdlib>
#include <vector>
#include <cmath>
#include <ostream>
#include "vector_utility.h"

template std::vector<int> operator+(const std::vector<int>&, const std::vector<int>&);
template std::vector<double> operator+(const std::vector<double>&, const std::vector<double>&);
template std::vector<int> operator-(const std::vector<int>&, const std::vector<int>&);
template std::vector<double> operator-(const std::vector<double>&, const std::vector<double>&);
template std::vector<double> teleport(const double, const int);
template std::ostream& operator<<(std::ostream&, const std::vector<double>&);
template std::ostream& operator<<(std::ostream&, const std::vector<int>&);
template double magnitude(const std::vector<double>);

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
