#include <iostream>
#include <string.h>
#include "v2.h"

using namespace std;

/*este es el programa para registro del paciente, esto lo va a usar el administrador, es decir el doctor*/

REGISTER registers[MAX_REGISTER];

int pos = 0;

void askData();
void addRegister(REGISTER *r);
void viewRegister();
void deleteRegister(int id);
void editRegister(REGISTER *r, int id);
void showData(REGISTER &r);
REGISTER identify_id(int id);
int menu();
void inicio();
int obtPos(int id);
void show_Data();
void edit_data();
void showRegisterbyID();
void removeData();
int getValidID();




//esto lo hice para restringir la id a solo numeritos 
int getValidID(){
    int id;
    while(true)/*ciclo repetitivo como cuando intentas adivinar una contraseña 
    y sigues intentándolo hasta que lo logras.
    Se inicia un ciclo while que se repetirá indefinidamente 
    (true significa que siempre será verdad, por lo tanto, el ciclo sigue ejecutándose).*/{
        cout << "Ingrese el ID del regristro (solamente numeros): ";
        cin >> id;
        if(cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n'); /*En la función getValidID(), INT_MAX se usa para limpiar y descartar entradas no 
            válidas del buffer de entrada (cin); INT_MAX: Le dice a cin.ignore que ignore hasta INT_MAX caracteres.*/ 
            cout << "Error, ingrese un numero valido.\n";
        }else{
            cin.ignore(INT_MAX, '\n'); //esto descarta una entrada extra
            return id;
        }
    }
}


void askData(){
    REGISTER r;
    r.id = getValidID();
    cout << "\033[1;32mIngrese el nombre del paciente: \033[0m";
    scanf(" %[^\n]", r.name);
    cout << "\033[1;32mIngrese el apellido del paciente: \033[0m";
    scanf(" %[^\n]", r.lastName);
    cout << "\033[1;32mIngrese la direccion de domicilio del paciente: \033[0m";
    scanf(" %[^\n]", r.address);
    cout << "\033[1;32mIngrese el telefono del paciente: \033[0m";
    scanf(" %[^\n]", r.number);
    cout << "\033[1;32mIngrese la edad del paciente: \033[0m";
    scanf(" %[^\n]", r.age);
    cout << "\033[1;32mIngrese el genero del paciente (masculino o femenino): \033[0m"; //mejorar esto para que solo se puedan elegir dos opciones 
    scanf(" %[^\n]", r.gender);
    cout << "\033[1;32mIngrese el historial medico del paciente: \033[0m";
    scanf(" %[^\n]", r.medicalHistory);
    cout << "\033[1;32mIngrese los la razon del la cita:  \033[0m";
    scanf(" %[^\n]", r.consultationReason);
}

REGISTER identify_id(int id){
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

int obtPos(int id){
    for(int i = 0; i < pos; i++){
        if(registers[i].id == id){
            return i;
        }
    }
    return -1;
}

void addRegister(REGISTER *r){
    if(pos < MAX_REGISTER){
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

void show_Data(){
    system("cls");
    for(int i = 0; i < pos; i++){
        showData(registers[i]);
    }
    cout << "presiones enter para continuar";
    cin.ignore();
    cin.get();
}

void showData(REGISTER &r){
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

void edit_data(){
    int id = getValidID();
    REGISTER r = identify_id(id);
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
    REGISTER r = identify_id(id);
    if(r.id != 0){
        showData(r);
    }else{
        cout << "no se encuentra el registro\n";
    }
    cout << "presione enter";
    cin.ignore();
    cin.get();
}

int menu(){
    int option;
    cout << "\033[1;94m****************Menu de registro***************\033[0m\n";
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
                askData();
                break;
            case 2:
                show_Data();
                break;
            case 3:
                showRegisterbyID();
                break;
            case 4:
                edit_data();
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

















