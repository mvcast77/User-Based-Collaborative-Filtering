#ifndef VECTOR_UTILS
#define VECTOR_UTILS

#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);

template <typename T>
std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b);

template <typename T>
std::vector<T> operator-(const std::vector<T>& a, const std::vector<T>& b);

template <typename T>
std::vector<T> teleport(const T d, const int total);

template <typename T>
T magnitude(const std::vector<T> vec);
#endif
