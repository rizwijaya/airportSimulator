#include "Plane.hpp" // mengaitkan dengan header yang ada disana
// Plane Initialization

Plane::Plane(int flt, int time, Plane_status status) // 
/* Post: Anggota data The Plane-> flt_num, clock_start, and state diset pada nilai dr
 parameters flt, time and status, respectively. */
{
    flt_num = flt;
    clock_start = time;
    state = status;
    cout << "Plane number " << flt << " ready to ";
    if (status == arriving)
        cout << "land." << endl;
    else
        cout << "take off." << endl;
}
Plane :: Plane( )
/* Post: The Plane data members flt_num, clock_start, state di set ke illegal default values. */
{
    flt_num = -1;
    clock_start = -1;
    state = null;
}

void Plane :: refuse( ) const
/* Post: Proses ketika pesawat ingin ke Runway, when the Queue is full. */
{
    cout << "Plane number " << flt_num;
    if (state == arriving)
        cout << " directed to another airport" << endl;
    else
        cout << " told to try to takeoff again later" << endl;
}


void Plane :: land(int time) const
/* Post: Waktu spesifik saat pesawat sedang LDG. */
{
    int wait = time - clock_start;
    cout << time << ": Plane number " << flt_num << " landed after " <<wait<<"time unit"<<((wait == 1)?"":"s")
         << " in the takeoff queue." << endl;
}

void Plane :: fly(int time) const
/* Post: Waktu spesifik ketika pesawat proses T/O. */
{
    int wait = time - clock_start;
    cout << time << ": Plane number " << flt_num << " took off after " <<wait<<"time unit"<<((wait == 1)?"":"s")
         << " in the takeoff queue." << endl;
}

int Plane :: started( ) const
/* Post: Return the time that the Plane entered the airport system.  */
{
    return clock_start;
}
