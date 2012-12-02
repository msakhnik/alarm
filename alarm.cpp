#include "alarm.h"

using namespace std;

cAlarm::cAlarm()
{
    cerr << "In construct" << endl;
    _time = time(NULL);
}

bool cAlarm::SetTime()
{
    int hour;
    cout << "Enter hour: ";
    cin >> hour;
    if (hour < 0 && hour >= 24)
    {
        cerr << "Its not hour" << endl;
        return false;
    }
    int minute;
    cout << "Enter minute: ";
    cin >> minute;
    if (minute < 0 && minute >= 60)
    {
        cerr << "Its not minute" << endl;
        return false;
    }
    _t_m = localtime(&_time);
    _t_m->tm_hour = hour;
    _t_m->tm_min = minute;

    return true;
}