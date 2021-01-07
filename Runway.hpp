#ifndef RUNWAY_HPP
#define RUNWAY_HPP
// Untuk menghindari deklarasi ganda dari Random.hpp

#include <queue>
#include "Plane.hpp"
#include "utility.hpp"
#include "Queue.hpp"

using namespace std;

enum Runway_activity {idle, land, take};
class Runway
{
public:
    Runway(int limit);
    Error_code can_land(const Plane &current);
    Error_code can_depart(const Plane &current);
    Runway_activity activity(int time,
                             Plane &moving);
    void shut_down(int time) const;
private:
    Queue landing;
    Queue takeoff;
    int queue_limit;
    int num_land_requests;    // Jumlah banyaknya pesawat meminta untuk LDG
    int num_takeoff_requests;    // Jumlah banyaknya pesawat meminta untuk T/O
    int num_landings;    // Jumlah pesawat yang telah LDG 
    int num_takeoffs;    // Jumlah pesaawat yang sedang T/O 
    int num_land_accepted;    // Jumlah pesawat yang sedang holding procedures to LDG (Inbound procedure)
                              // Depends on Airport whic is have a VOR/DME, ILS, or NDB
    int num_takeoff_accepted;    // Jumlah pesawat antri pada taxiway menuju runway utk T/O
    int num_land_refused;    // Jumlah pesawat ditolak dalam LDG
    int num_takeoff_refused;    // Jumlah pesawat yang ditolak T/O
    int land_wait;    // TOtal waktu pesawat dalam holding (menunggu LDG) 
    int takeoff_wait;    // Total waktu pesawat menunggu untuk take off
    int idle_time;    // Jumlah waktu ketika dalam keadaan kosong Runway nya
};


#endif
