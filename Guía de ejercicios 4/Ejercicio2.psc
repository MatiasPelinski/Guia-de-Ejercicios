Algoritmo Ejercicio2
	Definir contador como real
	Definir cantidadnotas,notas Como entero;
	
	Escribir "Ingrese la cantidad de notas que se van a cargar" 
		leer cantidadnotas
	Dimension vector(cantidadnotas)
	
	Escribir "Ingrese las notas"
		para i<- 1 hasta cantidadnotas Hacer
			leer notas
				si notas >= 6 Entonces
					contadoraprobados <- contadoraprobados+1
				SiNo
					contadordesaprobados <- contadordesaprobados+1
				FinSi
		FinPara
	
	
	Escribir "La cantidad de aprobados es de " contadoraprobados " y la cantidad de desaprobados es de " contadordesaprobados
	
	
FinAlgoritmo
