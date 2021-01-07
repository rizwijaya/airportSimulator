#include "Queue.hpp"

Queue::Queue (int limit) // class dan methodnya 
{						 // Menginisialisasi nilai queue, kalau di C mirip dengan init dan malloc.
	MAX_SIZE = limit; // menentukan ukuran maksimal
	index = new Plane[limit]; // indexing dari queue nya
	_size = 0; // inisialisasi ukuran
	front = 0; // bagian depan queue dibuat spt itu
	rear = MAX_SIZE - 1; // inisialisasi bagian belakang menyesuaikan dari ukuran max dari qeueue

}

Error_code Queue::append(const Plane &item) // menambah nilai qeueue dari belakang (adding from tail)
{
	if ( full() ) // Kalo penuh maka langsung overflow
		return overflow;

	rear = (rear + 1) % MAX_SIZE; //menambahkan belakang tail queue 
	index[rear] = item;
	_size++;

	return success; // dengan return value sukses
}

Error_code Queue::serve() // menghapus value queue
{
	if ( empty() ) // kalo kosong langsung kasih underflow
		return underflow;

	front = (front + 1) % MAX_SIZE; // menghapus data dari depan front
	_size--; //kurangi size dari queue

	return success; // nilai balikan sukses
}

Error_code Queue::retrieve(Plane &item) const // Menginisialisasi nilai item ke queue paling depan (front) di qeueue
{
	if (_size <= 0) return underflow;
	item = index[front];
	return success;
}
int Queue::size() const // mendapat kan ukuran dari queue
{
	return _size;
}

bool Queue::empty() const // mengecek kosong dari suatu queue
{
	return _size == 0;
}

bool Queue::full() const // mengecek penuh dari suatu queue
{
	return _size == MAX_SIZE;
}

Queue::~Queue() { // untuk menghapus index dari queue
	if (index)
		delete[] index;
	index = NULL;
}
