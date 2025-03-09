#ifndef OUT_UTIL
#define OUT_UTIL

template <typename T>
struct Data {
	std::vector<std::pair<unsigned, T>> vec;
	unsigned current;
	Data(std::vector<std::pair<unsigned, T>>& input, unsigned count): vec(input), current(count) {}
};

template <typename T>
std::ostream& operator<<(std::ostream& file, Data<T>& datum){
	for (const auto& par : datum.vec) file << datum.current << " " << par.first << " " << par.second << "\n";

	return file;
}

#endif
