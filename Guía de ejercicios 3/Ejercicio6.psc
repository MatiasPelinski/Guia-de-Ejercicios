Algoritmo Ejercicio6
	Definir menortiempo como real;
	menortiempo<- 9999999
	
	para i <- 1 hasta 12 hacer
		Escribir  "ingrese el número del vehiculo"
		leer numvehiculo
		Escribir "Ingrese el timepo del vehículo"
		leer tiempovehiculo
		
		si tiempovehiculo < menortiempo Entonces
			menortiempo <- tiempovehiculo
			vehiculoganador <- numvehiculo
		FinSi
	FinPara
	
	Escribir "El numero del vehiculo ganador es de " menortiempo
	Escribir "Y el tiempo de este es de " vehiculoganador " segundos " 
FinAlgoritmo
