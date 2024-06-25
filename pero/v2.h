#include <iostream>
#include <string.h>

using namespace std;

#define MAX_REGISTER 50
struct REGISTER{
    int id;
    char name[20];
    char lastName[20];
    char address[30];
    char number[10];
    char gender[10];
    char age[3];
    char consultationReason[30];
    char medicalHistory[50];
};