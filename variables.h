
#include <iostream>
using namespace std;


#define MAX_APPOINTMENT 50

struct SCHEDULE{
    char hour[2];
    char minute[2]; 
};

struct DATE{
    char day[2];
    char year[4];
    char month[2];
};

struct APPOINTMENT{
    int id;
    char namePatient[20];
    char treatment[50];
    SCHEDULE time;
    DATE dates;
};
