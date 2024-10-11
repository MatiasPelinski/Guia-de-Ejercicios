/*Se tiene un archivo con el siguiente formato de registro
    -Provincia
    -Ciudad
    -Escuela (numero)
    -grado (1 a 7)
    -cantidad de Alumnos
El cual se halla ordenado por provincia, dentro de cada provincia por ciudad, dentro de cada ciudad
por número de escuela, en todos los casos en forma creciente. Se quiere obtener un listado con la
cantidad total de alumnos por escuela, por ciudad, por provincia y el total del país, según el
siguiente formato de salida
    Provincia
    Ciudad
    Escuela ----- Cantidad Alumnos*/

#include <iostream>
#include <cstring>
using namespace std;

struct registro
{
    char provincia[50];
    char ciudad[50];
    int numeroEscuela;
    int grado;
    int cantidadAlumnos;
    registro *Siguiente;
};

registro *nuevoRegistro(char *provincia, char *ciudad, int numeroEscuela, int grado, int cantidadAlumnos)
{
    registro *nuevoRegistro = new registro;
    strcpy(nuevoRegistro->provincia, provincia);
    strcpy(nuevoRegistro->ciudad, ciudad);
    nuevoRegistro->numeroEscuela = numeroEscuela;
    nuevoRegistro->grado = grado;
    nuevoRegistro->cantidadAlumnos = cantidadAlumnos;
    nuevoRegistro->Siguiente = nullptr;
    return nuevoRegistro;
}

void agregarRegistro(registro *cabecera, registro *nuevoRegistro)
{
    registro*aux = cabecera;
    while(aux->Siguiente != nullptr)
    {
        aux = aux->Siguiente;
    }
     aux->Siguiente = nuevoRegistro;
}

void mostrarRegistro(registro*cabecera)
{
    registro*aux = cabecera;
    while(aux!=nullptr)
    {
        cout << "Provincia:" << aux->provincia << endl;
        cout << "Ciudad:" << aux->ciudad << endl;
        cout << "Numero de la escuela: " << aux->numeroEscuela << endl;
        cout << "Grado: " << aux->grado << endl;
        cout << "Cantidad de alumnos: " << aux->cantidadAlumnos << endl;
        cout << "-----------------------------------" << endl;
        aux = aux->Siguiente;
    } 
}

int main()
{
    registro*cabecera=nuevoRegistro("Misiones","Posadas",456,4,25);
    mostrarRegistro(cabecera);
    return 0;
}