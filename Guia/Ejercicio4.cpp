#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define tam 3

struct Categoria
{
    string categoria;
};

struct Libros
{
    int codigo;
    string nombreLibro;
    struct Categoria cat;
} Lib[tam];

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

void IngresarLibros()
{
    for (int i = 0; i < tam; i++)
    {

        Lib[i].codigo = i + 1;
        cout << "Nombre del Libro: " << endl;
        cin >> Lib[i].nombreLibro;
        cout << "Nombre de la Categoria: " << endl;
        cin >> Lib[i].cat.categoria;
    }
}

void MostrarLibros()
{
    for (int i = 0; i < tam; i++)
    {
        cout << "Codigo del Libro: |" << Lib[i].codigo << "|\t";
        cout << "Nombre del Libro: |" << Lib[i].nombreLibro << "|\t";
        cout << "Categoria: |" << Lib[i].cat.categoria << "|\t";
        cout << "\n";
    }
    system("pause");
}

void MostrarLibrosByCodigo()
{
    int codigo = 0;
    bool libroEncontrado = false;
    cout << "Ingrese el codigo del libro:";
    cin >> codigo;
    cout << "\n";
    for (int i = 0; i < tam; i++)
    {
        if (Lib[i].codigo == codigo)
        {
            cout << "Codigo del Libro: |" << Lib[i].codigo << "|\t";
            cout << "Nombre del Libro: |" << Lib[i].nombreLibro << "|\t";
            cout << "Categoria: |" << Lib[i].cat.categoria << "|\t";
            cout << "\n";
            libroEncontrado = true;
        }
    }
    if (!libroEncontrado)
    {
        cout << "No se Encontro el Libro..." << endl;
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
        cout << "1.Registrar Nuevo Libro\n";
        cout << "2.Mostrar Libros\n";
        cout << "3.Buscar un Libro\n";
        cout << "4.Salir\n";
        cout << "Seleccione una opcion del 1 al 4:";
        cin >> op;
        op = selectOpcion(op, 1, 4);
        switch (op)
        {
        case 1:
            IngresarLibros();
            break;
        case 2:
            MostrarLibros();
            break;
        case 3:
            MostrarLibrosByCodigo();
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