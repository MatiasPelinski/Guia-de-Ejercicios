#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

// Estructura de los libros
struct Libro
{
    string titulo;
    string autor;
    int anioEdicion;
    string editorial;
    string ISBN;
    int numPaginas;
    Libro *siguiente;
};

// Estructura de los lectores
struct Lector
{
    string nombre;
    string dni;
    string libroSolicitado;
    Lector *siguiente;
};

Libro *cabeza = nullptr;
Lector *frente = nullptr;
Lector *final = nullptr;
string historial[100];
int indiceHistorial = 0;

// Funciones
void agregarHistorial(const string &accion)
{
    if (indiceHistorial < 100)
    {
        historial[indiceHistorial++] = accion;
    }
}

void cargarLibrosDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    while (archivo)
    {
        string titulo, autor, editorial, ISBN;
        int anioEdicion, numPaginas;
        getline(archivo, titulo, ',');
        getline(archivo, autor, ',');
        archivo >> anioEdicion;
        archivo.ignore();
        getline(archivo, editorial, ',');
        getline(archivo, ISBN, ',');
        archivo >> numPaginas;
        archivo.ignore();

        if (!titulo.empty())
        {
            Libro *nuevoLibro = new Libro{titulo, autor, anioEdicion, editorial, ISBN, numPaginas, cabeza};
            cabeza = nuevoLibro;
        }
    }
    archivo.close();
}

void agregarLibro(const string &titulo, const string &autor, int anioEdicion, const string &editorial, const string &ISBN, int numPaginas)
{
    Libro *nuevoLibro = new Libro{titulo, autor, anioEdicion, editorial, ISBN, numPaginas, cabeza};
    cabeza = nuevoLibro;
    agregarHistorial("Agregar libro: " + titulo);
}

void mostrarLibros()
{
    if (!cabeza)
    {
        cout << "No hay libros en la biblioteca." << endl;
        return;
    }
    Libro *actual = cabeza;
    while (actual)
    {
        cout << "Titulo: " << actual->titulo << ", Autor: " << actual->autor
             << ", Anio: " << actual->anioEdicion << ", Editorial: " << actual->editorial
             << ", ISBN: " << actual->ISBN << ", Paginas: " << actual->numPaginas << endl;
        actual = actual->siguiente;
    }
}

void ordenarLibros()
{
    if (!cabeza || !cabeza->siguiente)
    {
        cout << "No hay suficientes libros para ordenar." << endl;
        return;
    }

    bool intercambiado;
    do
    {
        intercambiado = false;
        Libro *actual = cabeza;
        Libro *anterior = nullptr;
        Libro *siguiente = cabeza->siguiente;

        while (siguiente)
        {
            if (actual->titulo > siguiente->titulo)
            {
                
                actual->siguiente = siguiente->siguiente;
                siguiente->siguiente = actual;

                if (anterior)
                {
                    anterior->siguiente = siguiente;
                }
                else
                {
                    cabeza = siguiente;
                }

                intercambiado = true;
                anterior = siguiente;
                siguiente = actual->siguiente;
            }
            else
            {

                anterior = actual;
                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
        }
    } while (intercambiado);

    cout << "Libros ordenados por titulo." << endl;
}

void eliminarLibroDeLista(const string &libroSolicitado)
{
    Libro *actual = cabeza;
    Libro *anterior = nullptr;

    while (actual)
    {
        if (actual->titulo == libroSolicitado)
        {
            if (anterior)
            {
                anterior->siguiente = actual->siguiente;
            }
            else
            {
                cabeza = actual->siguiente;
            }
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

void eliminarLibroDelArchivo(const string &libroSolicitado)
{
    ifstream archivo("biblioteca.txt");
    ofstream temp("temp.txt");
    string titulo, autor, editorial, ISBN;
    int anioEdicion, numPaginas;

    while (getline(archivo, titulo, ','))
    {
        getline(archivo, autor, ',');
        archivo >> anioEdicion;
        archivo.ignore();
        getline(archivo, editorial, ',');
        getline(archivo, ISBN, ',');
        archivo >> numPaginas;
        archivo.ignore();

        if (titulo != libroSolicitado)
        {
            temp << titulo << "," << autor << "," << anioEdicion << "," << editorial << "," << ISBN << "," << numPaginas << endl;
        }
    }

    archivo.close();
    temp.close();
    remove("biblioteca.txt");
    rename("temp.txt", "biblioteca.txt");
}

bool verificarDNI(const string &dni)
{
    Lector *actual = frente;
    while (actual)
    {
        if (actual->dni == dni)
        {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void solicitarLibro(const string &dni, const string &nombre, const string &libro)
{
    if (nombre.empty() || dni.empty())
    {
        cout << "Error: Se necesita el nombre y el DNI para continuar." << endl;
        return;
    }

    Libro *actual = cabeza;
    while (actual)
    {
        if (actual->titulo == libro)
        {
            eliminarLibroDeLista(libro);
            eliminarLibroDelArchivo(libro);
            Lector *nuevoLector = new Lector{nombre, dni, libro, nullptr};
            if (!frente)
            {
                frente = final = nuevoLector;
            }
            else
            {
                final->siguiente = nuevoLector;
                final = nuevoLector;
            }
            cout << nombre << " ha solicitado el libro: " << libro << endl;
            agregarHistorial("Solicitar libro: " + libro + " por " + nombre);
            return;
        }
        actual = actual->siguiente;
    }
    cout << "El libro " << libro << " no esta disponible." << endl;
}

void devolverLibro(const string &libro)
{
    Lector *actual = frente;
    Lector *anterior = nullptr;

    while (actual)
    {
        if (actual->libroSolicitado == libro)
        {

            if (anterior)
            {
                anterior->siguiente = actual->siguiente;
            }
            else
            {
                frente = actual->siguiente;
            }
            if (actual == final)
            {
                final = anterior;
            }
            delete actual;

            Libro *nuevoLibro = new Libro{libro, "", 0, "", "", 0, cabeza};
            cabeza = nuevoLibro;
            agregarHistorial("Devolver libro: " + libro);

            ofstream archivo("biblioteca.txt", ios::app);
            archivo << libro << ",,,0,,0\n";
            archivo.close();

            cout << "Libro devuelto: " << libro << endl;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "El libro no esta en solicitudes." << endl;
}

void mostrarSolicitudes()
{
    Lector *actual = frente;
    if (!actual)
    {
        cout << "No hay solicitudes de libros." << endl;
    }
    else
    {
        while (actual)
        {
            cout << "Nombre: " << actual->nombre << ", DNI: " << actual->dni
                 << ", Libro solicitado: " << actual->libroSolicitado << endl;
            actual = actual->siguiente;
        }
    }
}

void buscarLibro(const string &titulo)
{
    Libro *actual = cabeza;
    while (actual)
    {
        if (actual->titulo == titulo)
        {
            cout << "Libro encontrado:\nTitulo: " << actual->titulo
                 << ", Autor: " << actual->autor << ", Anio: " << actual->anioEdicion
                 << ", Editorial: " << actual->editorial << ", ISBN: " << actual->ISBN
                 << ", Paginas: " << actual->numPaginas << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Libro no encontrado." << endl;
}

void mostrarHistorial()
{
    if (indiceHistorial == 0)
    {
        cout << "No hay acciones en el historial." << endl;
    }
    else
    {
        cout << "Historial de acciones:" << endl;
        for (int i = 0; i < indiceHistorial; ++i)
        {
            cout << historial[i] << endl;
        }
    }
}

void guardarSolicitudes()
{
    ofstream archivoSolicitudes("solicitudes.txt");
    Lector *actual = frente;
    while (actual)
    {
        archivoSolicitudes << "Nombre: " << actual->nombre << ", DNI: " << actual->dni
                           << ", Libro solicitado: " << actual->libroSolicitado << endl;
        actual = actual->siguiente;
    }
    archivoSolicitudes.close();
}

void guardarDatos(const string &nombreArchivoLibros)
{
    ofstream archivoLibros(nombreArchivoLibros);
    Libro *actualLibro = cabeza;
    while (actualLibro)
    {
        archivoLibros << actualLibro->titulo << "," << actualLibro->autor << ","
                      << actualLibro->anioEdicion << "," << actualLibro->editorial << ","
                      << actualLibro->ISBN << "," << actualLibro->numPaginas << endl;
        actualLibro = actualLibro->siguiente;
    }
    archivoLibros.close();
    guardarSolicitudes();
    agregarHistorial("Guardar datos");
    cout << "Datos guardados en archivos." << endl;
}

int main()
{
    cargarLibrosDesdeArchivo("biblioteca.txt");
    int opcion;
    do
    {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Mostrar libros" << endl;
        cout << "3. Ordenar libros por titulo" << endl;
        cout << "4. Solicitar libro" << endl;
        cout << "5. Devolver libro" << endl;
        cout << "6. Mostrar solicitudes" << endl;
        cout << "7. Buscar libro" << endl;
        cout << "8. Mostrar historial" << endl;
        cout << "9. Guardar datos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        {
            string titulo, autor, editorial, ISBN;
            int anioEdicion, numPaginas;
            cout << "Ingrese titulo: ";
            getline(cin, titulo);
            cout << "Ingrese autor: ";
            getline(cin, autor);
            cout << "Ingrese anio de edicion: ";
            cin >> anioEdicion;
            cin.ignore();
            cout << "Ingrese editorial: ";
            getline(cin, editorial);
            cout << "Ingrese ISBN: ";
            getline(cin, ISBN);
            cout << "Ingrese numero de paginas: ";
            cin >> numPaginas;
            cin.ignore();
            agregarLibro(titulo, autor, anioEdicion, editorial, ISBN, numPaginas);
            break;
        }
        case 2:
            mostrarLibros();
            break;
        case 3:
            ordenarLibros();
            break;
        case 4:
        {
            string dni, nombre, libro;
            cout << "Ingrese DNI del solicitante: ";
            getline(cin, dni);
            cout << "Ingrese nombre del solicitante: ";
            getline(cin, nombre);
            cout << "Ingrese libro solicitado: ";
            getline(cin, libro);
            solicitarLibro(dni, nombre, libro);
            break;
        }
        case 5:
        {
            string libro;
            cout << "Ingrese el titulo del libro a devolver: ";
            getline(cin, libro);
            devolverLibro(libro);
            break;
        }
        case 6:
            mostrarSolicitudes();
            break;
        case 7:
        {
            string titulo;
            cout << "Ingrese el titulo del libro a buscar: ";
            getline(cin, titulo);
            buscarLibro(titulo);
            break;
        }
        case 8:
            mostrarHistorial();
            break;

        case 9:
            guardarDatos("biblioteca.txt");
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    } while (opcion != 0);
    return 0;
}
