/*Diseñar un algoritmo que solicite las tres notas de la cursada de un alumno e indique si el alumno
está aprobado por medio de una función. Un alumno aprueba la cursada si las notas son todas
superiores a 4 y si el promedio de las tres es mayor o igual a 7.
Realizar la prueba de escritorio de los siguientes escenarios:
    Escenario 1: Nota 1: 3, Nota 2: 9, Nota 3: 9
    Escenario 2: Nota 1: 6, Nota 2: 8, Nota 3: 10 */

#include <iostream>
using namespace std;

int verificacionAprobado(int nota1, int nota2, int nota3)
{
    if (nota1 > 4 && nota2 > 4 && nota3 > 4)
    {
        return (nota1 + nota2 + nota3) / 3;
    }
    else
    {
        cout << "El alumno no aprobo la cursada" << endl;
        return 0;
    }
}

int main()
{
    int nota1, nota2, nota3;
    cout << "Ingrese la nota del alumno" << endl;
    cin >> nota1 >> nota2 >> nota3;
    int promedio = verificacionAprobado(nota1, nota2, nota3);
    if (nota1 > 4 && nota2 > 4 && nota3 > 4)
    {
        cout << "El promedio del alumno es de " << promedio;
    }
    return 0;
}