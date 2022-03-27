#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define fila 4
#define columna 3

/*
Funcion para seleccionar una opción de una lista

@op = Opción que ingresa el usuario
@rangoMinimo = La opción minima que puede seleccionar el usuario
@rangoMaximo = La opción maxima que puede seleccionar el usuario
*/
int selectOpcion(int op, int rangoMinimo, int rangoMaximo)
{
    while (op < rangoMinimo || op > rangoMaximo)
    {
        cout << "Ingrese una opcion valida entre (" << rangoMinimo << "-" << rangoMaximo << "):" << endl;
        cin >> op;
    }
    return op;
}
/*
Funcion para mostrar un elemento en especifico del arreglo

@thisArray = Arreglo que vamos a mostrar en pantalla
@numeroFila = numero filas que contiene nuestro arreglo multidimensional
@codigo = posición del indice en el arreglo
*/
void mostrarElementosByCodigo(string thisArray[][columna], int numeroFilas, int codigo)
{
    bool elementoEncontrado = false;
    for (int i = 0; i < numeroFilas; i++)
    {
        if (thisArray[i] == thisArray[codigo])
        {
            cout << "Nombre: |" << thisArray[i][0] << "|\t";
            cout << "Apellido: |" << thisArray[i][1] << "|\t";
            cout << "Edad: |" << thisArray[i][2] << "|\t";
            cout << "\n"
                 << endl;
        }
    }
}

string tablaUsuarios[fila][columna] = {
    {"Luis", "Flores", "21"},
    {"Brayan", "Gonzales", "20"},
    {"Flor", "Maria", "20"},
    {"Marisol", "Sosa", "18"}
};

int main()
{
    int op = 0;
    cout << "Buscar usuario\n";
    cout << "Ingrese el codigo del 0 al " << (fila - 1) << ":";
    cin >> op;
    op = selectOpcion(op, 0, (fila - 1));
    mostrarElementosByCodigo(tablaUsuarios, fila, op);

    return 0;
}