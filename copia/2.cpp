#include <iostream>
#include <string.h>
#include "v.h"

/*entonces, esta es para las funciones de agendar cita, esta casi complet
falta validar con otra librera, ajustar el locale.h y ajustar ciertos errores
de usuario que puedo tener*/

using namespace std;

APPOINTMENT appointments[MAX_APPOINTMENTS];
REGISTER registers[MAX_REGISTERS];


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

//funciones para el registro

void askRegisterData();
void addRegister(REGISTER *r);
void viewRegister();
void deleteRegister(int id);
void editRegister(REGISTER *r, int id);
void showRegisterData(REGISTER &r);
REGISTER identifyRegisterByID(int id);
int menuRegister();
void inicio();
void showRegisters();
void editRegisterData();
void showRegisterByID();
void removeData();

//funciones paarea convertir, ver los tratamientos, lows horarios, el menu 
void ShowDentalTreatments();
void showPricesInDolares();
void showClinicHours();
void menuPaciente();
void menuAdministrador();
void mainMenu();



void askData(){
    APPOINTMENT a;
    a.id = getValidID();
    cout << "\033[1;32mIngrese su nombre: \033[0m";
    scanf(" %[^\n]", a.namePatient);
    cout << "\033[1;32mIngrese el tratamiento: \033[0m";
    scanf(" %[^\n]", a.treatment);
    cout << "\033[1;32mIngrese el dia de la cita (dd): \033[0m";
    scanf(" %[^\n]", a.dates.day);
    cout << "\033[1;32mIngrese el mes de la cita (mm): \033[0m";
    scanf(" %[^\n]", a.dates.month);
    cout << "\033[1;32mIngrese el año de la cita (yyyy): \033[0m";
    scanf(" %[^\n]", a.dates.year);
    cout << "\033[1;32mIngrese la hora de la cita (hh): \033[0m";
    scanf(" %[^\n]", a.time.hour);
    cout << "\033[1;32mIngrese los minutos de la cita (mm): \033[0m";
    scanf(" %[^\n]", a.time.minute);
    addAppointement(&a);
}

APPOINTMENT identify_id(int id) {
    for (int i = 0; i < pos; i++) {
        if (appointments[i].id == id) {
            return appointments[i];
        }
    }
    APPOINTMENT a = {0, "", "", {"", ""}, {"", "", ""}};
    return a;
}

int obtPos(int id) {
    for (int i = 0; i < pos; i++) {
        if (appointments[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addAppointement(APPOINTMENT *a) {
    if (pos < MAX_APPOINTMENTS) {
        appointments[pos] = *a;
        pos++;
    } else {
        cout << "\033[1;31mNo se pueden agregar más citas.\033[0m\n";
    }
}

void editAppointment(APPOINTMENT *a, int id) {
    int posi = obtPos(id);
    if (posi != -1) {
        strcpy(appointments[posi].namePatient, a->namePatient);
        strcpy(appointments[posi].treatment, a->treatment);
        strcpy(appointments[posi].dates.day, a->dates.day);
        strcpy(appointments[posi].dates.month, a->dates.month);
        strcpy(appointments[posi].dates.year, a->dates.year);
        strcpy(appointments[posi].time.hour, a->time.hour);
        strcpy(appointments[posi].time.minute, a->time.minute);
    }
}

void deleteAppointment(int id) {
    int posi = obtPos(id);
    if (posi != -1) {
        for (int i = posi; i < pos - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        pos--;
    }
}

void show() {
    for (int i = 0; i < pos; i++) {
        showData(appointments[i]);
    }
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void appointmentxID() {
    int id = getValidID();
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

void showData(APPOINTMENT &a) {
    cout << "------------------------------------------------------" << endl;
    cout << "Numero de cita: " << a.id << endl;
    cout << "Nombre: " << a.namePatient << endl;
    cout << "Tratamiento: " << a.treatment << endl;
    cout << "Fecha: " << a.dates.day << "/" << a.dates.month << "/" << a.dates.year << endl;
    cout << "Hora: " << a.time.hour << ":" << a.time.minute << endl;
    cout << "-----------------------------------------------------" << endl;
}

void edit() {
    int id = getValidID();
    APPOINTMENT a = identify_id(id);
    if (a.id != 0) {
        cout << "Ingrese el nuevo nombre del paciente: ";
        cin.ignore();
        scanf(" %[^\n]", a.namePatient);
        cout << "Ingrese el nuevo tratamiento: ";
        scanf(" %[^\n]", a.treatment);

        // Editar fecha
        cout << "Ingrese el nuevo dia de la cita (dd): ";
        scanf(" %[^\n]", a.dates.day);
        cout << "Ingrese el nuevo mes de la cita (mm): ";
        scanf(" %[^\n]", a.dates.month);
        cout << "Ingrese el nuevo año de la cita (yyyy): ";
        scanf(" %[^\n]", a.dates.year);

        // Editar hora
        cout << "Ingrese la nueva hora de la cita (hh): ";
        scanf(" %[^\n]", a.time.hour);
        cout << "Ingrese los nuevos minutos de la cita (mm): ";
        scanf(" %[^\n]", a.time.minute);

        editAppointment(&a, id);
        cout << "Se actualizo su cita...\n";
    } else {
        cout << "Cita no encontrada.\n";
    }
    cout << "Presione enter para continuar";
    cin.ignore();
    cin.get();
}

void deleteData() {
    int id = getValidID();
    deleteAppointment(id);
    cout << "Cita eliminada.\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

int menu() {
    int option;
    cout << "\033[1;34mAgendar citas - Menu\033[0m\n";
    cout << "1. Agendar cita\n";
    cout << "2. Mostrar cita por ID\n";
    cout << "3. Buscar cita por ID\n";
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
        option = menu();
        switch (option) {
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

int getValidID() {
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

void showAppointmentByID() {
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


//aca empieza la funcion de registro

void ask_data(){
    REGISTER r;
    r.id = getValidID();
    cout << "\033[1;36mIngrese el nombre del paciente: \033[0m";
    scanf(" %[^\n]", r.name);
    cout << "\033[1;36mIngrese el apellido del paciente: \033[0m";
    scanf(" %[^\n]", r.lastName);
    cout << "\033[1;36mIngrese la direccion de domicilio del paciente: \033[0m";
    scanf(" %[^\n]", r.address);
    cout << "\033[1;36mIngrese el telefono del paciente: \033[0m";
    scanf(" %[^\n]", r.number);
    cout << "\033[1;36mIngrese la edad del paciente: \033[0m";
    scanf(" %[^\n]", r.age);
    cout << "\033[1;36mIngrese el genero del paciente (masculino o femenino): \033[0m"; //mejorar esto para que solo se puedan elegir dos opciones 
    scanf(" %[^\n]", r.gender);
    cout << "\033[1;36mIngrese el historial medico del paciente: \033[0m";
    scanf(" %[^\n]", r.medicalHistory);
    cout << "\033[1;36mIngrese los la razon del la cita:  \033[0m";
    scanf(" %[^\n]", r.consultationReason);
}


REGISTER identify(int id){
    for(int i = 0; i < pos; i++){
        if(registers[i].id == id){
            return registers[i];
        }
    }
    REGISTER r ={0, "", "", "", "", "", "", "", "", }; /*Esto es como decir "Si no encontramos la cita, devolvamos una 
    cita vacía para indicar que no se encontró", entones se inicializa 
    con valores por defecto.*/
    return r;
}

void addRegister(REGISTER *r){
    if(pos < MAX_REGISTERS){
        registers[pos] = *r;
        pos++;
    }else{
        cout << "\033[1;31mNo se pueden agregar mas registros\033[0m\n";
    }
} 

void editRegister(REGISTER *r, int id){
    int posi = obtPos(id);
    if(posi != -1){
        strcpy(registers[posi].name, r->name);
        strcpy(registers[posi].lastName, r->lastName);
        strcpy(registers[posi].address, r->address);
        strcpy(registers[posi].number, r->number);
        strcpy(registers[posi].age, r->age);
        strcpy(registers[posi].gender, r->gender);
        strcpy(registers[posi].medicalHistory, r->medicalHistory);
        strcpy(registers[posi].consultationReason, r->consultationReason);
    }
}

void deleteRegister(int id){
    int posi = obtPos(id);
    if(posi != -1){
        for(int i = posi; i < pos; i++){
            registers[i] = registers[i+1];
        }
        pos--;
    }
}

void showRegisterData(REGISTER &r){
    cout << "------------------------------------------------------"<< endl;
    cout <<"|" <<"Numero del registro: " << r.id << endl;
    cout <<"|" <<"Nombre y apellido: " << r.name  << endl;
    cout <<"|" <<"Direccion:         " << r.address<< endl;
    cout <<"|" <<"su numero de telefono: "<< r.number << endl;
    cout <<"|" <<"Edad:              " << r.age << endl; 
    cout <<"|" <<"Historial medico:  " << r.medicalHistory << endl;
    cout <<"|" <<"Razon de la cita:  " << r.consultationReason <<  endl;
    cout << "-----------------------------------------------------" << endl;
}

void showRegisters(){
    system("cls");
    for(int i = 0; i < pos; i++){
       showRegisterData(registers[i]);
    }
    cout << "presiones enter para continuar";
    cin.ignore();
    cin.get();
}

void editRegisterData(){
    int id = getValidID();
    REGISTER r = identify(id);
    if(r.id != 0){
        cout << "ingrese el nuevo nombre del paciente: \n";
        cin.ignore();
        scanf(" %[\n]", r.name);
        cout << "ingrese el nuevo apellido del paciente: \n ";
        scanf(" %[\n]", r.lastName);
        cout << "ingrese la nueva direccion del paciente: \n";
        scanf(" %[\n]", r.address);
        cout << "ingrese el nuevo numero de telefono del paciente: \n";
        scanf(" %[\n]", r.number);
        cout << "ingrese la nueva edad del paciente: \n";
        scanf(" %[\n]", r.age);
        editRegister(&r, id);
        cout << "registro editado\n";
    }else{
        cout << "no se encuentra el registro\n";
    }
    cout << "presione enter"; 
    cin.ignore();
    cin.get();
}

void removeData(){
    int id = getValidID();
    deleteRegister(id);
    cout << "registro eliminado\n";
    cout << "presione enter";
    cin.ignore();
    cin.get();
}

 //enfasis aqui
void showRegisterByID(){
    int id = getValidID();
    REGISTER r = identify(id);
    if(r.id != 0){
        showRegisterData(r);
    }else{
        cout << "no se encuentra el registro\n";
    }
    cout << "presione enter";
    cin.ignore();
    cin.get();
}

int menuRegister(){
    int option;
    cout << "\033[1;94m****************Menu de registro(Administrador)***************\033[0m\n";
    cout << "1. Agregar registro\n";
    cout << "2. Mostrar todos los registros\n";
    cout << "3. Mostrar registro segun ID\n";
    cout << "4. Editar registro\n";
    cout << "5. Eliminar registro\n";
    cout << "6. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> option;
    cin.ignore(INT_MAX, '\n');
    return option;
}

void inicio(){
    int option;
    do{
        system("cls");
        option = menu();
        switch(option){
            case 1:
                ask_data();
                break;
            case 2:
                showRegisters();
                break;
            case 3:
                showRegisterByID();
                break;
            case 4:
               editRegisterData();
                break;
            case 5:
             removeData();
             break;
            case 6:
                cout << "Saliendo\n";
                break;  
        }if(option != 6){
            cout << "presione enter";
            cin.ignore();
            cin.get();
        }
    }while(option != 6);
}

void ShowDentalTreatments(){
    cout << "----------tratamientos dentales disponibles (precios en cordobas)---------\n";
    cout << "1. Limpieza dental -- 650 C$\n";
    cout << "2. Restauracion de resina -- 750 C$\n";
    cout << "3. Protesis total -- 6,500 C$\n";
    cout << "4. Protesis removible -- 3,500 C$\n";
    cout << "5. Cirugia de tercer molar -- 3,000 C$\n";
    cout << "6. Extraccion convencional -- 500 C$\n";
}

void showPricesInDolares(){
    cout << "----------tratamientos dentales disponibles (precios en dolares)---------\n";
    cout << "1. Limpieza Dental - " << 650 / EXCHANGE_RATE << " $ \n";
    cout << "2. Restauracion de resina - " << 750 / EXCHANGE_RATE << " $ \n";
    cout << "3. Protesis total - " << 6500 / EXCHANGE_RATE << " $ \n";
    cout << "4. Protesis removible - " << 3500 / EXCHANGE_RATE << " $ \n";
    cout << "5. Cirugia de tercer molar - " << 3000 / EXCHANGE_RATE << " $ \n";
    cout << "5. Extraccion convencional- " << 500 / EXCHANGE_RATE << " $ \n";
}

void showClinicHours(){
    cout << "------------Horarios de atención disponibles------------\n";
    cout << "Lunes a Viernes: 8:00 AM - 12 PM / 1 PM - 5:00 PM\n";
    cout << "Sábados: 9:00 AM - 1:00 PM\n";
    cout << "Domingos: Cerrado\n";
}

void menuPaciente(){
    int option;
    do {
        cout << "\033[1;34mMenu de Paciente\033[0m\n";
        cout << "1. Ver tratamientos dentales\n";
        cout << "2. Ver precios en córdobas\n";
        cout << "3. Ver horarios de atención\n";
        cout << "4. Programar una cita\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                ShowDentalTreatments();
                break;
            case 2:
                showPricesInDolares();
                break;
            case 3:
                showClinicHours();
                break;
            case 4:
                principal(); // Función de gestión de citas
                break;
            case 5:
                cout << "saliendo\n";
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        }
        if (option != 6) {
            cout << "Presione Enter para continuar ";
            cin.ignore();
            cin.get();
        }
    } while (option != 6);
}

void mainMenu(){
    int user;
    do {
        cout << "\033[1;34mBienvenido al sistema de clinica dental los olivos\033[0m\n";
        cout << "elija su usuario: \n";
        cout << "1. Paciente\n";
        cout << "2. Administrador\n";
        cout << "3. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> user;
        cin.ignore();

        switch (user) {
            case 1:
                menuPaciente();
                break;
            case 2:
                menuRegister();
                break;
            case 3:
                cout << "Saliendo del sistema\n";
                break;
            default:
                cout << "Opción inválida. Por favor intente de nuevo.\n";
                break;
        }
        if (user != 3) {
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (user != 3);
}