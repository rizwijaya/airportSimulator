#ifndef QUEUE_HPP
#define QUEUE_HPP
// Untuk menghindari deklarasi ganda dari Random.hpp

#include "utility.hpp"
#include "Plane.hpp"
#include <iostream>

using namespace std;

class Queue {
public:
	Queue (int queue_limit);
	Error_code append(const Plane &item);
	Error_code serve();
	Error_code retrieve(Plane &item) const;
	int size() const;
	bool empty() const;
	bool full() const;
	~Queue();

private:
	int MAX_SIZE;
	int _size;
	int front;
	int rear;
	Plane *index;
};


#endif
