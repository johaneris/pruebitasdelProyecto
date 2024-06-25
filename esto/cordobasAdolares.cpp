#include <iostream>
#include "variable.h"

using namespace std;

CONVERSION conversions[MAX_CONVERSIONS];
int pos = 0;

void askData();
void addConversion(CONVERSION *c);
void viewConversions();
void deleteConversion(int id);
void editConversion(CONVERSION *c, int id);
void showData(CONVERSION &c);
CONVERSION identify_id(int id);
int menu();
void principal();
int obtPos(int id);
void show();
void edit();
void conversionxID();
void deleteData();

const double exchangeRate = 36.5; // Suponiendo que 1 dólar = 36.5 córdobas

void askData() {
    CONVERSION conversion;
    cout << "Ingrese el número de conversión: ";
    cin >> conversion.id;
    cout << "Ingrese la cantidad en córdobas: ";
    cin >> conversion.amountCordobas;
    conversion.amountDollars = conversion.amountCordobas / exchangeRate;
    addConversion(&conversion);
}

CONVERSION identify_id(int id) {
    for (int i = 0; i < pos; i++) {
        if (conversions[i].id == id) {
            return conversions[i];
        }
    }
    CONVERSION c;
    return c;
}

int obtPos(int id) {
    for (int i = 0; i < pos; i++) {
        if (conversions[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addConversion(CONVERSION *c) {
    conversions[pos] = *c;
    pos++;
}

void editConversion(CONVERSION *c, int id) {
    int posi = obtPos(id);
    conversions[posi].amountCordobas = c->amountCordobas;
    conversions[posi].amountDollars = c->amountCordobas / exchangeRate;
}

void deleteConversion(int id) {
    int posi = obtPos(id);
    for (int i = posi; i < pos - 1; i++) {
        conversions[i] = conversions[i + 1];
    }
    pos--;
}

void show() {
    for (int i = 0; i < pos; i++) {
        showData(conversions[i]);
    }
}

void conversionxID() {
    int id;
    cout << "Ingrese la id de la conversión: ";
    cin >> id;
    CONVERSION c = identify_id(id);
    showData(c);
}

void showData(CONVERSION &c) {
    cout << "------------------------------------" << endl;
    cout << "Número de conversión: " << c.id << endl;
    cout << "Cantidad en córdobas: " << c.amountCordobas << endl;
    cout << "Cantidad en dólares: " << c.amountDollars << endl;
    cout << "------------------------------------" << endl;
}

void edit() {
    int id;
    cout << "Ingrese la id de la conversión: ";
    cin >> id;
    CONVERSION c = identify_id(id);
    cout << "Ingrese la nueva cantidad en córdobas: ";
    cin >> c.amountCordobas;
    c.amountDollars = c.amountCordobas / exchangeRate;
    editConversion(&c, id);
    cout << "Se actualizó su conversión... \n";
}

void deleteData() {
    int id;
    cout << "Conversión - Eliminar\n";
    cout << "Ingrese la id de la conversión a eliminar: ";
    cin >> id;
    deleteConversion(id);
}

int menu() {
    int option;
    cout << "Conversor de Córdobas a Dólares - Menu\n";
    cout << "1. Agregar conversión\n";
    cout << "2. Mostrar conversiones\n";
    cout << "3. Buscar conversión por id\n";
    cout << "4. Editar conversión\n";
    cout << "5. Eliminar conversión\n";
    cout << "6. Salir\n";
    cout << "Ingrese una opción: ";
    cin >> option;
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
            show();
            break;
        case 3:
            conversionxID();
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
            cout << "Opción inválida\n";
            break;
        }
    } while (option != 6);
}
