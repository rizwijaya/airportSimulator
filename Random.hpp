#ifndef RANDOM_HPP
#define RANDOM_HPP
// Untuk menghindari deklarasi ganda dari Random.hpp

#include <iostream> 
#include <ctime>
#include <cmath>
using namespace std;

const int max_int = ~(1<<31); // meniadakan bit supaya tidak error,
							  // error dapat berupa overflow
							  // disini kita menentukan batasan bit nilai maxnya
							  // mulai dari 1 - 32 bit

class Random
{
	public:
		Random(bool pseudo = false);
		int poisson(double mean);	
	private:
		int reseed();
		double random_real();
		int seed;
		int multiplier;
		int add_on;	
};

#endif