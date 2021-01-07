#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <iomanip>
using namespace std;

enum Error_code { success, fail, overflow, underflow};

void initialize(int &end_time,int &queue_limit,
				double &arrival_rate,double &departure_rate,bool flag);

#endif
