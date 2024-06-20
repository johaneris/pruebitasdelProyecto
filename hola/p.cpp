#include <iostream>
#include "a.cpp"
#include <locale.h>

using namespace std;


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "spanish");
    principal();
    return 0;
}