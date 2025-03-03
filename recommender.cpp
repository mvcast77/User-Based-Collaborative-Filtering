#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "csr_utility.h"
//#include "vector_utility.h"

int main(int argc, char ** argv){
	if (argc < 2){
		std::cerr << "Expected format is ./a.out <input file>\n";
		return EXIT_FAILURE;
	}
	std::ifstream file {argv[1]};
	//Might want to do an error check here

	CSR<int> * csr_input = new CSR<int>;
	file >> csr_input;
	std::cout << csr_input;
//
//	CSR<double> * csr = new CSR<double>;
//	std::cout << transpose(csr_input, csr);
//	
//	unsigned N = csr->ptr.size() - 1;
//	double vo_start = 1 / (double) N;
//
//	std::vector<double> V;
//	std::vector<double> Vo;
//	for (unsigned i = 0; i < N; ++i){
//		V.push_back(0.0);
//		Vo.push_back(vo_start);
//	}
//
//	(*csr) *= d;
//
//	std::vector<double> I = teleport(d, N);
//		
//	double epsilon = 1e-10;
//	unsigned iterations = 0;
//	while (magnitude( V - Vo) > epsilon){
//		Vo = V;
//		V = csr * Vo + I;
//		++iterations;
//	}
//
//	std::cout << "Number of iterations: " << iterations << "\n";
//
//	std::cout << "Final result\n" << V;
//	double sum = 0.0;
//	for (const auto& val : V) sum += val;
//	std::cout << "Sum of page ranks: " << sum << "\n";
//
//	delete csr;
	delete csr_input;
	return 0;
}
