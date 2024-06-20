#include <iostream>
using namespace std;


/*agendar citas*/

#define MAX_APPOINTMENT 50

struct SCHEDULE{
    char hour[3];
    char minute[3]; 
};

struct DATE{
    char day[3];
    char year[5];
    char month[3];
};

struct APPOINTMENT{
    int id;
    char namePatient[20];
    char treatment[50];
    SCHEDULE time;
    DATE dates;
};
