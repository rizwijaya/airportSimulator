#include "Random.hpp"

Random::Random(bool pseudo) // mengecek apakah nilainya true atau tidak untuk mendapatkan nilai seed
{
	if(pseudo) seed = 1;
	else seed = time(NULL) % max_int;
	multiplier = 2743;
	add_on = 5923;
			
}

int Random::poisson(double mean) // Mencerminkan distribusi dari poison random, lebih detilnya ada dimateri bilangan
								 // Metode ini berhubungan dengan waktu (interval)
{
	double limit = exp(-mean); // untuk mengembalikan nilai exponensial bilangan euler.
	double product = random_real();
	int count = 0;
	while (product > limit)
	{
		count++;
		product *= random_real();
	}
	return count; // mengembalikan nilai count
}

int Random::reseed() // Untuk menginisialisasi nilai seed dari Pseudo random.
{
	seed = seed * multiplier + add_on;
	return seed; 
}

double Random::random_real() // Mengacak angka antara 0 dan 1 (Pasti 0 atau 1)
{
	double max = max_int +1.0;
	double temp = reseed();
	if (temp<0) temp = temp + max;
			
	return temp/max;
}