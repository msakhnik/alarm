#include <iostream>
#include <string.h>
#include <getopt.h>
#include "alarm.h"

using namespace std;

static char const* _Basename(char const* fname)
{
    char const* res = strrchr(fname, '/');
    return res ? res + 1 : fname;
}

static void _ReadHelp(const char *progname)
{
    cout << "Gnome Alarm (galarm)\n\n"
            "Synopsis:\n"
            "  " << progname << " [options] file\n\n"
            "Options:\n"
            "  -s,--set-time\tSet time for alarm\n"
            "  -h,--help\t\tThis help message\n\n"
            << endl;
}

int main(int argc, char** argv)
{
    char const* progname = _Basename(argv[0]);

    bool set_time = false;
    cAlarm alarm;
    
    while (true)
    {
        static struct option long_options[] ={
            { "set-time", no_argument, 0, 's'},
            { "help", no_argument, 0, 'h'},
            { 0, 0, 0, 0}
        };

        int c = 0;
        int option_index = 0;

        c = getopt_long(argc, argv, "sh",
                        long_options, &option_index);
        if (c == -1)
            break;

        switch (c)
        {
        case 'h':
            _ReadHelp(progname);
            return 0;

        case 's':
            set_time = true;
            break;

        default:
            cerr << "Unknown option '" << c << "'" << endl;
            return 1;
        }
    }
    if (!alarm.SetTime())
        return -1;
        
    
    return 0;
}