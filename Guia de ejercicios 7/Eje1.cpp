#include <iostream>
#include <cstring>
using namespace std;

struct Libro
{
    char codigo[50];
    char autor[50];
    char titulo[50];
    char editorial[50];
    int precioUnitario;
    int stock;
    Libro *Siguiente;
};

struct Movimiento
{
    char fecha[50];
    char codigoLibro[50];
    int cantidadVendida;
    Movimiento *Siguiente;
};

Libro *crearLibro(char *codigo, char *autor, char *titulo, char *editorial, int precioUnitario, int stock)
{
    Libro *nuevoLibro = new Libro;
    strcpy(nuevoLibro->codigo, codigo);
    strcpy(nuevoLibro->autor, autor);
    strcpy(nuevoLibro->titulo, titulo);
    strcpy(nuevoLibro->editorial, editorial);
    nuevoLibro->precioUnitario = precioUnitario;
    nuevoLibro->stock = stock;
    nuevoLibro->Siguiente = nullptr;
    return nuevoLibro;
};

Movimiento *nuevoMovimiento(char *fecha, char *codigoLibro, int cantidadVendida)
{
    Movimiento *nuevoMovimiento = new Movimiento;
    strcpy(nuevoMovimiento->fecha, fecha);
    strcpy(nuevoMovimiento->codigoLibro, codigoLibro);
    nuevoMovimiento->cantidadVendida = cantidadVendida;
    nuevoMovimiento->Siguiente = nullptr;
    return nuevoMovimiento;
}

void agregarLibroALista(Libro *cabecera, Libro *nuevoLibro)
{
    Libro *aux = cabecera;
    while (aux->Siguiente != nullptr)
    {
        aux = aux->Siguiente;
    }
    aux->Siguiente = nuevoLibro;
}

void agregarMovimiento(Movimiento *cabeceraa, Movimiento *nuevoMovimiento0)
{
    Movimiento *aux = cabeceraa;
    while (aux->Siguiente != nullptr)
    {
        aux = aux->Siguiente;
    }
    aux = aux->Siguiente;
}

void mostrarLibros(Libro *cabecera)
{
    Libro*aux = cabecera;
    while (aux != nullptr)
    {
        cout << "Codigo: " << aux->codigo << endl;
        cout << "Autor: " << aux->autor << endl;
        cout << "Titulo: " << aux->titulo << endl;
        cout << "Editorial: " << aux->editorial << endl;
        cout << "Precio por unidad: " << aux->precioUnitario << endl;
        cout << "Stock disponible: " << aux->stock << endl;
        cout << "-----------------------------" << endl;
        aux = aux->Siguiente;
    }
    
}
int main()
{
    Movimiento *cabeceraa = nuevoMovimiento("12/03/21", "454-896-898", 12);
    Libro *cabecera = crearLibro("1215-521-412-21", "Alan Poe", "La casa", "Pearson", 40000.45, 20);
    
    mostrarLibros(cabecera);
    return 0;
}