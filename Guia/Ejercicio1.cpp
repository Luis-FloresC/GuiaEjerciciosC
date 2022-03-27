#include <iostream>
#include <ctime>
#include <cstdlib>
#include<windows.h>
using namespace std;
#define tamanioArreglo 10



/*
Funcion para seleccionar una opción de una lista

@op = Opción que ingresa el usuario
@rangoMinimo = La opción minima que puede seleccionar el usuario
@rangoMaximo = La opción maxima que puede seleccionar el usuario
*/
int selectOpcion(int op,int rangoMinimo,int rangoMaximo){
    while(op < rangoMinimo || op > rangoMaximo)
    {
        cout << "Ingrese una opcion valida entre (" << rangoMinimo << "-" << rangoMaximo << "):" << endl;
        cin >> op;
    }
    return op;
}
/*
Funcion para mostrar un elemento en especifico del arreglo

@thisArray = Arreglo que vamos a mostrar en pantalla
@numeroDeElemntos = tamaño del arreglo
@codigo = posición del indice en el arreglo
*/
void mostrarElementosByCodigo(string thisArray[],int numeroDeElemntos,int codigo){    
    for (int i = 0; i < numeroDeElemntos; i++)
    {
        if(thisArray[i] == thisArray[codigo])
        {
            cout << "Departamento: " << thisArray[codigo] << endl;
        }
    }  
}

/*
Funcion para mostrar todos los elemntos de un arreglo
@thisArray = Arreglo que vamos a mostrar en pantalla
@numeroDeElemntos = tamaño del arreglo
*/
void mostrarElementos(string thisArray[],int numeroDeElemntos){
    for (int i = 0; i < numeroDeElemntos; i++)
    {
        cout  << i + 1 <<"-(" << thisArray[i] << ")";
        cout << "\n";
    }
}

string tablaDeptos[tamanioArreglo] = {"Francisco Morazan","El Paraiso","Olancho","Atlantida","Choluteca","Copan","Cortes","Yoro","La Paz","Lempira"};
int main()
{
    int op=0;
    cout << "Departamentos de Honduras" << endl;
    mostrarElementos(tablaDeptos,tamanioArreglo);
    cout << "Seleccione una opcion del 1 al " << tamanioArreglo << ":";
    cin >> op;
    op = selectOpcion(op,1,tamanioArreglo);
    system("cls");
    mostrarElementosByCodigo(tablaDeptos,tamanioArreglo,(op-1));
    return 0;
}