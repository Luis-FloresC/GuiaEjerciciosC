#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define fila 10
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
            cout << "Marca: |" << thisArray[i][0] << "|\t";
            cout << "Modelo: |" << thisArray[i][1] << "|\t";
            cout << "Anio: |" << thisArray[i][2] << "|\t";
            cout << "\n"
                 << endl;
        }
    }
}

string tablaVehiculos[fila][columna] = {
    {"Honda", "Civic", "2010"},
    {"BMW", "BMW x3", "2018"},
    {"Audi", "Audi TT Rs Roadster", "2018"},
    {"Mercedes Benz", "A-Class A220", "2018"},
    {"Honda", "Civic 2.0", "2012"},
    {"BMW", "BMW x4", "2018"},
    {"Audi", "Audi TT Rs 5 Roadster", "2018"},
    {"Mercedes Benz", "B-Class A220", "2018"},
    {"Ford Fiesta", "1.0 Ecoboost", "2018"},
    {"Ford Fiesta", "2.0 Ecoboost", "2020"}};
int main()
{
    int op = 0;
    cout << "Seleccione una opcion del 0 al " << (fila - 1) << ":";
    cin >> op;
    op = selectOpcion(op, 0, (fila - 1));
    mostrarElementosByCodigo(tablaVehiculos, fila, op);

    return 0;
}