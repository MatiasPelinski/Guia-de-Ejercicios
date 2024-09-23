Algoritmo Ejercicio4
	flag <- 0
	definir i,edad, personas como entero
	Dimension personas(20)
	Escribir "Ingrese la edades de las personas "
	
	para i <- 1 hasta 20 Hacer
		leer personas(20)
			si flag = 0 Entonces
				pmenoredad <- personas(20)
				flag <- 1
			FinSi
			si personas(20) < pmenoredad Entonces
				pmenoredad <- personas(20)
			FinSi
	contadorpersonas <- contadorpersonas+1
	totaledades <- totaledades + personas(20)	
FinPara
Escribir "La persona mas joven tiene " pmenoredad " y el promedio de edad es de " totaledades/contadorpersonas
	
FinAlgoritmo
