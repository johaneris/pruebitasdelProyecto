#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char op;
    do  
    {
        //muestro el menu
        cout << "-----Menu-----" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Usuario" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: "; 
        //op lee la opcion que ingrese el usuario
        cin >> op;

        //El switch evalua la opcion seleccionada por el usuario
        switch (op)
        {
        case 1:
            cout << "Ha seleccionado la opcion 1" << endl;
                    //aqui iria el codigo de la primera opcion
            break;
        case 2:
            cout << "Ha seleccionado la opcion 2" << endl;
                    //aqui iria el codigo de la segunda opcion
            break;
        case 3:
            cout << "Saliendo del programa" << endl;    
            break;
        default:
            cout << "Opcion no valida, por favor seleccione una opcion valida";
            break;
        }
    } while (op!='3');
        cout << "Adios, vuelva pronto" << endl;
    
    return 0;
}