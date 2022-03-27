#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define tam 15

struct Departamentos
{
    string nombreDepartamento;
};

struct Municipios
{
    int codigo;
    string nombreMunicipio;
    struct Departamentos depto;
} Mun[tam];

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

void Registrar()
{
    for (int i = 0; i < tam; i++)
    {
        system("cls");
        cout << "Municipio #" << i + 1 << endl;
        Mun[i].codigo = i + 1;
        cout << "Nombre del Municipio " << endl;
        cin >> Mun[i].nombreMunicipio;
        cout << "Departamento: " << endl;
        cin >> Mun[i].depto.nombreDepartamento;
    }
}

void MostrarTodos()
{
    for (int i = 0; i < tam; i++)
    {
        cout << "Municipio #" << i + 1 << endl;
        cout << "Codigo: |" << Mun[i].codigo << "|\n";
        cout << "Nombre del Municipio: |" << Mun[i].nombreMunicipio << "|\n";

        cout << "Departamento: |" << Mun[i].depto.nombreDepartamento << "|\n";
        cout << "\n";
    }
    system("pause");
}

void MostrarMunicipioByCodigo()
{
    int codigo = 0;
    bool municipioEncontrado = false;
    cout << "Ingrese el codigo del municipio:";
    cin >> codigo;
    cout << "\n";
    for (int i = 0; i < tam; i++)
    {
        if (Mun[i].codigo == codigo)
        {
            cout << "Municipio #" << i + 1 << endl;
            cout << "Codigo: |" << Mun[i].codigo << "|\n";
            cout << "Nombre del Municipio: |" << Mun[i].nombreMunicipio << "|\n";

            cout << "Departamento: |" << Mun[i].depto.nombreDepartamento << "|\n";
            cout << "\n";
            municipioEncontrado = true;
        }
    }
    if (!municipioEncontrado)
    {
        cout << "No se Encontro el municipio..." << endl;
    }
    system("pause");
}

void Menu()
{
    int op = 0;
    do
    {
        system("cls");
        cout << "Menu Principal\n";
        cout << "1.Registrar Municipios\n";
        cout << "2.Mostrar Municipios\n";
        cout << "3.Buscar un Municipio\n";
        cout << "4.Salir\n";
        cout << "Seleccione una opcion del 1 al 4:";
        cin >> op;
        op = selectOpcion(op, 1, 4);
        switch (op)
        {
        case 1:
            Registrar();
            break;
        case 2:
            MostrarTodos();
            break;
        case 3:
            MostrarMunicipioByCodigo();
            break;
        case 4:
            break;
        }
    } while (op != 4);
}

int main()
{
    Menu();
    return 0;
}