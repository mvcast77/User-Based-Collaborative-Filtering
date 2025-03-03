#ifndef CSR_UTIL
#define CSR_UTIL


template <typename T>
struct CSR {
	CSR(){}
	std::vector<T> values;
	std::vector<int> indices;
	std::vector<int> ptr;
	unsigned columns;
	std::vector<T> vector_mult(const std::vector<T>& x) const;
	void operator*=(const T coefficient);
};

template <typename T>
std::vector<T> operator*(const CSR<T>* csr, const std::vector<T>& x);

template <typename T>
CSR<T>* transpose(CSR<T>* old, CSR<T>* newby);

template <typename T>
std::istream& operator>>(std::istream& file, CSR<T>* csr);

template <typename T>
std::ostream& operator<<(std::ostream& os, const CSR<T>* csr);

#endif
