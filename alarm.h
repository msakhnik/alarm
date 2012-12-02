#pragma once

#include <time.h>
#include <iostream>

class cAlarm
{
public:
    cAlarm();
    bool SetTime();
    bool RunAlarm();
private:
    time_t _time;
    struct tm *_t_m;
    static struct timer_list my_timer;
};