#ifndef VECTOR_UTILS
#define VECTOR_UTILS

#include <ostream>

template <typename T>
std::istream& operator>>(std::istream& file, std::vector<std::pair<unsigned,T>>& vec);

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

template <typename A, typename B>
bool second_item(const std::pair<A,B>& left, const std::pair<A,B>& right);

template <typename T>
std::vector<std::pair<unsigned,T>> split(std::vector<std::pair<unsigned,T>>& x);

template <typename T>
void clear_nan(std::vector<std::pair<unsigned,T>>& vec);

#endif
