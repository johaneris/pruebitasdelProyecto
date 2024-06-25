#include <iostream>
#include <string.h>
#include "v.h"
using namespace std;

APPOINTMENT appointments[MAX_APPOINTMENT];
int pos = 0;

void askData();
void addAppointement(APPOINTMENT *a);
void viewAppointments();
void deleteAppointment(int id);
void editAppointment(APPOINTMENT *a, int id);
void showData(APPOINTMENT &a);
APPOINTMENT identify_id(int id);
int menu();
void principal();
int obtPos(int id);
void show();
void edit();
void appointmentxID();
void deleteData();
int getValidID();
void showAppointmentByID();
void clearScreen();


void askData(){
    APPOINTMENT a;
    a.id = getValidID();
    cout << "\033[1;35mIngrese el numero de su cita: \033[0m";
    cin >> a.id;
    cin.ignore(); 
    cout << "\033[1;35mIngrese su nombre: \033[0m";
    scanf(" %[^\n]", a.namePatient);
    cout << "\033[1;35mIngrese el tratamiento: \033[0m";
    scanf(" %[^\n]", a.treatment);
    cout << "\033[1;35mIngrese la fecha de la cita (ddmmyyyy): \033[0m";
    scanf(" %[^\n]", a.date);
    cout << "\033[1;35mIngrese la hora de la cita (hh): \033[0m";
    scanf(" %[^\n]", a.hour);
    cout << "\033[1;35mIngrese los minutos de la cita (mm): \033[0m";
    scanf(" %[^\n]", a.minute);
    addAppointement(&a);
}

APPOINTMENT identify_id(int id){
    for(int i = 0; i < pos; i++){
        if(appointments[i].id == id){
            return appointments[i];
        }
    }
    APPOINTMENT a = {0, "", "", "", "", ""};
    return a;
}

int obtPos(int id){
    for(int i = 0; i < pos; i++){
        if(appointments[i].id == id){
            return i;
        }
    }
    return -1;
}

void addAppointement(APPOINTMENT *a){
    if (pos < MAX_APPOINTMENT) {
        appointments[pos] = *a;
        pos++;
    } else {
        cout << "\033[1;31mNo se pueden agregar más citas.\033[0m\n";
    }
}

void editAppointment(APPOINTMENT *a, int id){
    int posi = obtPos(id);
    if (posi != -1) {
        strcpy(appointments[posi].namePatient, a->namePatient);
        strcpy(appointments[posi].treatment, a->treatment);
        strcpy(appointments[posi].date, a->date);
        strcpy(appointments[posi].hour, a->hour);
        strcpy(appointments[posi].minute, a->minute);
    }
}

void deleteAppointment(int id){
    int posi = obtPos(id);
    if (posi != -1) {
        for(int i = posi; i < pos - 1; i++){
            appointments[i] = appointments[i + 1];
        }
        pos--;
    }
}

void show(){
    clearScreen();
    for(int i = 0; i < pos; i++){
        showData(appointments[i]);
    }
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void appointmentxID(){
    int id;
    cout << "Ingrese el id de la cita: ";
    cin >> id;
    APPOINTMENT a = identify_id(id);
    if (a.id != 0) {
        showData(a);
    } else {
        cout << "Cita no encontrada.\n";
    }
    cout << "Presione enter para continuar ";
    cin.ignore();
    cin.get();
}

void showData(APPOINTMENT &a){
    cout << "------------------------------------" << endl;
    cout << "Numero de cita: " << a.id << endl;
    cout << "Nombre: " << a.namePatient << endl;
    cout << "Tratamiento: " << a.treatment << endl;
    cout << "Fecha: " << a.date << endl;
    cout << "Hora: " << a.hour << ":" << a.minute << endl;
    cout << "------------------------------------" << endl;
}

void edit(){
    int id;
    cout << "Ingrese la id de la cita: ";
    cin >> id;
    APPOINTMENT a = identify_id(id);
    if (a.id != 0) {
        cout << "Ingrese el nuevo nombre del paciente: ";
        cin.ignore();
        scanf(" %[^\n]", a.namePatient);
        cout << "Ingrese el nuevo tratamiento: ";
        scanf(" %[^\n]", a.treatment);
        cout << "Ingrese la nueva fecha de la cita: ";
        scanf(" %[^\n]", a.date);
        cout << "Ingrese la nueva hora de la cita: ";
        scanf(" %[^\n]", a.hour);
        cout << "Ingrese los nuevos minutos de la cita: ";
        scanf(" %[^\n]", a.minute);
        editAppointment(&a, id);
        cout << "Se actualizo su cita...\n";
    } else {
        cout << "Cita no encontrada.\n";
    }
    cout << "Presione enter para continuar";
    cin.ignore();
    cin.get();
}

void deleteData(){
    int id;
    cout << "Cita - Eliminar\n";
    cout << "Ingrese la id de la cita a eliminar: ";
    cin >> id;
    deleteAppointment(id);
    cout << "Cita eliminada.\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

int menu(){
    int option;
    cout << "\033[1;34mAgendar citas - Menu\033[0m\n";
    cout << "1. Agendar cita\n";
    cout << "2. Mostrar citas\n";
    cout << "3. Buscar cita\n";
    cout << "4. Editar cita\n";
    cout << "5. Eliminar cita\n";
    cout << "6. Mostrar todas las citas\n";
    cout << "7. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> option;
    cin.ignore(INT_MAX, '\n'); // pal buffer
    return option;
}

void principal() {
    int option;
    do {
        clearScreen();
        option = menu();
        switch(option) {
            case 1:
                askData();
                break;
            case 2:
                showAppointmentByID();
                break;
            case 3:
                appointmentxID();
                break;
            case 4:
                edit();
                break;
            case 5:
                deleteData();
                break;
            case 6:
                show();
                break;
            case 7:
                cout << "Saliendo\n";
                break;
            default:
                cout << "Opcion invalida\n";
                break;
        }
        if (option != 7) {
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (option != 7);
}


//cfunciones adicionales para probar

int getValidID(){
    int id;
    while (true) {
        cout << "Ingrese el numero de su cita (solo numeros): ";
        cin >> id;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(INT_MAX, '\n'); // Discard the invalid input
            cout << "Entrada invalida. Por favor ingrese un numero valido.\n";
        } else {
            cin.ignore(INT_MAX, '\n'); // Discard any extra input
            return id;
        }
    }
}


void showAppointmentByID(){
    int id = getValidID();
    APPOINTMENT a = identify_id(id);
    if (a.id != 0) {
        showData(a);
    } else {
        cout << "Cita no encontrada.\n";
    }
    cout << "Presione enter para continuar";
    cin.ignore();
    cin.get();
}

void clearScreen(){
    #if defined(_WIN32) || defined(_WIN64)
        system("CLS");
    #else
        system("clear");
    #endif
}

