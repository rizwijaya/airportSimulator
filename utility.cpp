#include "utility.hpp"

void initialize (int &end_time, int &queue_limit,
            double &arrival_rate, double &departure_rate)
/* Pre: Pengguna menentukan jumlah unit waktu dalam simulasi, maksimal
ukuran antrian diizinkan, dan perkiraan tingkat kedatangan dan keberangkatan untuk
Bandara.
Posting: Program mencetak instruksi dan menginisialisasi parameter end_time,
queue_limit, arrival_rate, dan departure_rate ke nilai yang ditentukan.
Kegunaan: fungsi utilitas user_says_yes */
{
    cout << "This program simulates an airport with only one runway." << endl
         << "One plane can land or depart in each unit of time." << endl;
    cout << "Up to what number of planes can be waiting to land "
         << "or take off at any time? " << flush;
    cin >> queue_limit;
    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;
    bool acceptable;
    do
    {
        cout << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cout << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "These rates must be nonnegative." << endl;
        else
            acceptable = true;
        if (acceptable && arrival_rate + departure_rate > 1.0)
            cerr << "Safety Warning: This airport will become saturated. " <<
                 endl;
    }
    while (!acceptable);
}

