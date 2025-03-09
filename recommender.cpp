#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "csr_utility.h"
#include "vector_utility.h"
#include "out_utility.h"

int main(int argc, char ** argv){
	if (argc < 4){
		std::cerr << "Expected format is ./a.out <train file> <test file> <output file>\n";
		return EXIT_FAILURE;
	}
	std::ifstream file {argv[1]};
	//Might want to do an error check here

	CSR<double> * user_ratings = new CSR<double>;
	file >> user_ratings;
	file.close();
	std::cout << user_ratings;

	std::ifstream new_file {argv[2]};
	std::ofstream log {argv[3]};

	std::vector<std::pair<unsigned, double>> unknown;
	new_file >> unknown;

	for (const auto& par : unknown) std::cout << "(" << par.first << ", " << par.second << ")\n";

	std::vector<std::pair<unsigned, double>> want = split(unknown);

	std::vector<std::pair<unsigned, double>> result = user_ratings->cosine(unknown);
	clear_nan(result);

	std::sort(result.begin(), result.end(), second_item<unsigned, double>);

	for (const auto& x : result) std::cout << "(" << x.first << ", " << x.second << ")\n";

	cosine_predictions(want, result, user_ratings, 10);

	for (const auto& x : want) std::cout << "(" << x.first << ", " << x.second << ")\n";

	/* unknown.clear();
	new_file >> unknown;
	Remember to split()
	for (const auto& par : unknown) std::cout << "(" << par.first << ", " << par.second << ")\n"; */
	Data d(want, 201);
	log << d;

	new_file.close();
	log.close();
	delete user_ratings;
	return 0;
}
