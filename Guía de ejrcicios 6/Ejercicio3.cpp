/*Diseñar un algoritmo que solicite los tres lados de un triángulo y determine qué tipo de triángulo
es: Equilátero, Escaleno o Isósceles por medio de una función.
Realizar la prueba de escritorio de los siguientes escenarios:
    Escenario 1: Lado 1: 10, Lado 2: 15, Lado 3: 20
    Escenario 2: Lado 1: 30, Lado 2: 30, Lado 3: 30
    Escenario 3: Lado 1: 20, Lado 2: 20, Lado 3: 30 */

#include <iostream>
using namespace std;

int determinacionTriangulo (int lado1, int lado2, int lado3){
    if(lado1 == lado2 && lado2 == lado3){
        cout << "Este triangulo es un equilatero" << endl;
        return 0; 
    }
    else if(lado1 == lado2 || lado2 == lado3){
        cout << "Este triangulo es un isosceles" << endl;
        return 0;
    }
    else {
        cout << "Este triangulo es un escaleno" << endl;
        return 0;
    }
}

int main (){
    int lado1,lado2,lado3;
    cout << "Ingrese los tres lados de su triangulo" << endl;
    cin >> lado1 >> lado2 >> lado3;
    determinacionTriangulo(lado1,lado2,lado3);
}