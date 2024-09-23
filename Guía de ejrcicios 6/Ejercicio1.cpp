/*Diseñar un algoritmo que solicite la edad de dos hermanos y devuelva un mensaje indicando cuál
de los dos es mayor y cuantos años de diferencia tiene con el menor, por medio de una función.
Nota: Contemplar que ambos hermanos puedan tener la misma edad.
Realizar la prueba de escritorio de los siguientes escenarios:
    Escenario 1: Hermano 1: 25, Hermano 2: 29
    Escenario 2: Hermano 1: 23, Hermano 2: 18
    Escenario 3: Hermano 1: 20, Hermano 2: 20 */

#include <iostream>
using namespace std;

int calculoDeHermanoMayor(int hermano1, int hermano2)
{
    if (hermano1 > hermano2)
    {
        cout << "El hermano mayor es el primero" << endl;
        return hermano1 - hermano2;
    }
    else if (hermano1 < hermano2)
    {
        cout << "El hermano mayor es el segundo" << endl;
        return hermano2 - hermano1;
    }
    else
    {
        cout << "Los dos tienen la misma edad" << endl;
        return 0;
    }
}

int main()
{
    int hermano1;
    int hermano2;

    cout << "Ingrese la edad del primer hermano" << endl;
    cin >> hermano1;
    cout << "Ingrese la edad del segundo hermano" << endl;
    cin >> hermano2;
    int diferencia = calculoDeHermanoMayor(hermano1, hermano2);
    cout << "La diferencia de edad es: " << diferencia << endl;
    return 0;
}