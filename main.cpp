#include <cstdlib>
#include <iostream>
#include "utility.cpp"
#include "Queue.cpp"
#include "Plane.cpp"
#include "Runway.cpp"
#include "Random.cpp"

using namespace std;

int main( ) // program simulasi bandara
{/*
    Input : Pengguna diminta untuk memasukan jumlah interval waktu simulasi akan dijalankan, 
            jumlah pesawat yang diharapkan tiba, jumlah pesawat yang diharapkan berangkat per interval waktu, 
            dan ukuran maksimum yang diizinkan dalam antrian runway(landasan pacu).
    
    Output: Program ini melakukan simulasi bandara secara acak,
            menunjukan status landasan pacu pada setiap interval waktu, 
            dan mencetak ringkasan pengoperasian bandara di akhir.
        
    Dibutuhkan : Class Runway, Plane
                 Random, dan fungsi run_idel serta initialize.

*/
    int end_time; // waktu yang dibutuhkan selama simulasi
    int queue_limit; // ukuran dari Queue nya Runway
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize(end_time, queue_limit, arrival_rate, departure_rate); // memanggil fungsi initialize dengan parameter yang dibawa
    Random variable; // Inisialisasi kelas random agar method nya dapat dipanggil misal poisson  
    Runway small_airport(queue_limit); // Inisialisasi kelas Runway disimpan ke small_airport
    for (int current_time = 0; current_time < end_time; current_time++) // perulangan selama interval waktu simulasi
    {    
        int number_arrivals = variable.poisson(arrival_rate); // Inisialisasi variable permintaan kedatangan saat ini
        for (int i = 0; i < number_arrivals; i++)
        {
            Plane current_plane(flight_number++, current_time, arriving); // Proses random number dari arriving
            if (small_airport.can_land(current_plane) != success) // Pengecekan semisal tidak bisa landing pada small_airport
                current_plane.refuse( ); // maka ditolak
        }
        
        int number_departures = variable.poisson(departure_rate); // Inisialisasi variable permintaan kedatangan saat ini
        for (int j = 0; j < number_departures; j++)
        {
            Plane current_plane(flight_number++, current_time, departing); // Proses random number dari departing
            if (small_airport.can_depart(current_plane) != success) // Pengecekan apakah pada small airport tidak dapat berangkat 
                current_plane.refuse( ); // maka ditolak
        }

        Plane moving_plane; // Inisialisasi kelas Plane dengan nama baru
        switch (small_airport.activity(current_time, moving_plane)) // Mengatur gerak dari pesawat 
        {
// Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane.land(current_time); // persilahkan untuk LDG
            break;
        case take:
            moving_plane.fly(current_time); // persilahkan untuk T/O
            break;
        case idle:
            run_idle(current_time); // Kalo runway kosong
        }
    }
    small_airport.shut_down(end_time);
}
