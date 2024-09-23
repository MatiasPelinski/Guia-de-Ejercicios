/*Diseñar un algoritmo que solicite dos números: a y b, y que devuelva ambos valores ordenados de
menor a mayor en una funcion.
Realizar la prueba de escritorio de los siguientes escenarios:
    Escenario 1: a: 5, b: 9
    Escenario 2: a: 8, b: 3*/

#include <iostream>
using namespace std;

int orderNumbers(int number1, int number2)
{
    if (number1 > number2)
    {
        cout << "El orden de los numeros es de " << number2 << "  " << number1 << endl;
        return 0;
    }
    else
    {
        cout << "El orden de los numeros es de " << number1 << "  " << number2 << endl;
        return 0;
    }
}

int main()
{
    int number1;
    int number2;
    cout << "Escriba los 2 numeros que desea ordenar" << endl;
    cin >> number1 >> number2;
    orderNumbers(number1,number2);
    return 0;
}