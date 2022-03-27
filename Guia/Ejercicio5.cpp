#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define tam 2

struct DetalleVenta
{
    int cantidad;
    int precio;
};

struct Ventas
{
    int codigo;
    float subTotal;
    string nombreProducto;
    struct DetalleVenta dtv;
} Ven[tam];

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

void NuevaVenta()
{
    for (int i = 0; i < tam; i++)
    {
        cout << "Detalle #" << i + 1 << endl;
        Ven[i].codigo = i + 1;
        cout << "Nombre del Producto: " << endl;
        cin >> Ven[i].nombreProducto;
        cout << "Precio del Producto: " << endl;
        cin >> Ven[i].dtv.precio;
        Ven[i].dtv.precio = selectOpcion(Ven[i].dtv.precio, 1, 1000);
        cout << "Cantidad del Producto: " << endl;
        cin >> Ven[i].dtv.cantidad;
        Ven[i].dtv.cantidad = selectOpcion(Ven[i].dtv.cantidad, 1, 99);

        Ven[i].subTotal = Ven[i].dtv.precio * Ven[i].dtv.cantidad;
    }
}

void MostrarVentas()
{
    for (int i = 0; i < tam; i++)
    {
        cout << "Venta #" << i + 1 << endl;
        cout << "Codigo de la venta: |" << Ven[i].codigo << "|\n";
        cout << "Nombre del producto: |" << Ven[i].nombreProducto << "|\n";

        cout << "Precio: |" << Ven[i].dtv.precio << "|\n";
        cout << "Cantidad: |" << Ven[i].dtv.cantidad << "|\n";
        cout << "Sub Total: |" << Ven[i].subTotal << "|\n";
        cout << "\n";
    }
    system("pause");
}

void MostrarVentasByCodigo()
{
    int codigo = 0;
    bool VentaEncontrada = false;
    cout << "Ingrese el codigo de la venta:";
    cin >> codigo;
    cout << "\n";
    for (int i = 0; i < tam; i++)
    {
        if (Ven[i].codigo == codigo)
        {
            cout << "Venta #" << i + 1 << endl;
            cout << "Codigo de la venta: |" << Ven[i].codigo << "|\n";
            cout << "Nombre del producto: |" << Ven[i].nombreProducto << "|\n";
            cout << "Precio: |" << Ven[i].dtv.precio << "|\n";
            cout << "Cantidad: |" << Ven[i].dtv.cantidad << "|\n";
            cout << "Sub Total: |" << Ven[i].subTotal << "|\n";
            cout << "\n";
            VentaEncontrada=true;
        }
    }
    if(!VentaEncontrada){
        cout <<  "No se Encontro la venta..." << endl;
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
        cout << "1.Nueva venta\n";
        cout << "2.Mostrar ventas\n";
        cout << "3.Buscar una venta\n";
        cout << "4.Salir\n";
        cout << "Seleccione una opcion del 1 al 4:";
        cin >> op;
        op = selectOpcion(op, 1, 4);
        switch (op)
        {
        case 1:
            NuevaVenta();
            break;
        case 2:
            MostrarVentas();
            break;
        case 3:
            MostrarVentasByCodigo();
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