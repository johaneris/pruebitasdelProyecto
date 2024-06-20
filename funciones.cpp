
#include <iostream>
#include <string.h>
#include "variables.h"
using namespace std;


APPOINTMENT appointments[MAX_APPOINTMENT];

int pos = 0;

//aca estoy agregando las funciones 
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





void askData(){
    APPOINTMENT appointments;
    cout << "Ingrese el numero de su cita: ";
    cin >> appointments.id;
    cin.ignore(); //probando eso
    cout << "Ingrese su nombre: ";
    scanf(" %[^\n]", appointments.namePatient);
    cout << "Ingrese el tratamiento: ";
    scanf(" %[^\n]", appointments.treatment);
    cout << "Ingrese la fecha de la cita: ";
    scanf(" %[^\n]", appointments.time.date);
    cout << "Ingrese la hora de la cita: ";
    scanf(" %[^\n]", appointments.time.hour);
    cout << "Ingrese los minutos de la cita: ";
    scanf(" %[^\n]", appointments.time.minute);
}

APPOINTMENT identify_id(int id){
    for(int i = 0; i < pos; i++){
        if(appointments[i].id == id){
            return appointments[i];
        }
    }
    APPOINTMENT a;
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
    appointments[pos] = *a;
    pos++;
}


void editAppointment(APPOINTMENT *a, int id){
    int posi =obtPos(id);
    strcpy(appointments[posi].namePatient, a->namePatient);
    strcpy(appointments[posi].treatment, a->treatment);
}

void deleteAppointment(int id){
    int posi =obtPos(id);
    for(int i = posi; i < pos; i++){
        appointments[i] = appointments[i+1];
    }
    pos--;
}
void show(){
    for(int i = 0; i < pos; i++){
    showData(appointments[i]);
    }
    
}

void appointmentxID(){
    int id;
    cout << "Ingrese la id de la cita: ";
    cin >> id;
    APPOINTMENT a;
    a = identify_id(id);
    showData(a);
}


void showData(APPOINTMENT &a){
    cout << "------------------------------------" << endl;
    cout << "Numero de cita: " << a.id << endl;
    cout << "Nombre: " << a.namePatient << endl;
    cout << "Tratamiento: " << a.treatment << endl;
    cout << "Fecha: " << a.date << endl;
    cout << "Hora: " << a.hour << endl;
    cout << "------------------------------------" << endl;

}

void edit(){
    int id;
    cout << "Ingrese la id de la cita: ";
    cin >> id;
    APPOINTMENT a = identify_id(id);
    cout << "Ingrese el nuevo nombre del paciente: ";
    cin.ignore();
    scanf(" %[^\n]", a.namePatient);
    cout << "Ingrese el nuevo tratamiento: ";
    scanf(" %[^\n]", a.treatment);
    editAppointment(&a, id);
    cout << "Se actualizo su cita... \n";
}

void deleteData(){




    int id;
    cout << "Cita - Eliminar\n";
    cout << "Ingrese la id de la cita a eliminar: ";
    cin >> id;
    deleteAppointment(id);
}


int menu(){
    int option;
    cout << "Agendar citas - Menu\n";
    cout << "1. Agendar cita\n";
    cout << "2. Mostrar citas\n";
    cout << "3. Buscar cita por id\n";
    cout << "4. Editar cita\n";
    cout << "5. Eliminar cita\n";
    cout << "6. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> option;
    return option;
}


void principal(){
    int option;
    do{
        option = menu();
        switch(option){
        case 1: 
            askData(); 
            break;
        case 2:
            show();
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
            cout << "Saliendo\n";
            break;
        default:
            cout <<"opcion invalida\n";
            break;
        }
    }while (option != 6);
}
