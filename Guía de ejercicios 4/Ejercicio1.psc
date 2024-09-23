Algoritmo Ejercicio1
	definir vector,notamasalta,promedio,flag,totalnotas,contador como real;
	Definir catidadnotas Como Entero;
	flag <- 0
	contador <- 0
	Escribir "Ingrese la cantidad de notas que se van a cargar"
	leer cantidadnotas
	Dimension vector(cantidadnotas)
	
	para i <- 1 hasta cantidadnotas hacer
		Escribir "Ingrese las notas"
			leer notas
		contador <- contador+1
				si flag = 0 Entonces
					notamasalta <- notas 
					flag <- 1
				FinSi
				si notas > notamasalta Entonces
					notamasalta <- notas
				FinSi
					totalnotas <- totalnotas + notas
	FinPara
	promedio <- totalnotas/contador
	Escribir "La nota mas alta es" notamasalta " y " "Y el promedio de las " contador " notas es de " promedio
FinAlgoritmo
