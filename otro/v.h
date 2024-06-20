

#include <iostream>
using namespace std;

#define MAX_APPOINTMENT 50

struct APPOINTMENT {
    int id;
    char namePatient[20];
    char treatment[50];
    char date[8];
    char hour[2];
    char minute[2];
};
