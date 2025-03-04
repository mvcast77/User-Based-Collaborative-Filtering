#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "csr_utility.h"
#include "vector_utility.h"

int main(int argc, char ** argv){
	if (argc < 3){
		std::cerr << "Expected format is ./a.out <train file> <test file>\n";
		return EXIT_FAILURE;
	}
	std::ifstream file {argv[1]};
	//Might want to do an error check here

	CSR<int> * user_ratings = new CSR<int>;
	file >> user_ratings;
	std::cout << user_ratings;

	std::vector<std::pair<unsigned, int>> unknown;
	std::ifstream new_file {argv[2]};
	new_file >> unknown;

	for (const auto& par : unknown) std::cout << "(" << par.first << ", " << par.second << ")\n";
	//std::sort(unknown.begin(), unknown.end(), second_item<unsigned, int>);

	std::vector<std::pair<unsigned, double>> result = user_ratings->cosine(unknown);

	for (const auto& x : result) std::cout << "(" << x.first << ", " << x.second << ")\n";

	delete user_ratings;
	return 0;
}
