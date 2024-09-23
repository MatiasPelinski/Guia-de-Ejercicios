Algoritmo Ej2
	Definir matriz como entero
	
	Dimension matriz[4,4]
	
para i <- 1 Hasta 4 Hacer	// i <- filas
	para j <- 1 Hasta 4 Hacer // j <- columnas
		si i+j =5 Entonces
		matriz[i,j] = 1 	
		SiNo
		matriz[i,j] = 0 
		FinSi
	FinPara
FinPara

para i <- 1 Hasta 4 Hacer
	para j <- 1 Hasta 4 Hacer
		Escribir Sin Saltar matriz[i,j], " "
		
	FinPara
	Escribir " "
FinPara
	
FinAlgoritmo
