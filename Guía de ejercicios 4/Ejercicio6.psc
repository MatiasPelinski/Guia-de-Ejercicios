Algoritmo Ejercicio6
	Definir cantidades,costos,i,j como entero
	
	dimension cantidades(1)
	//dimension costos(j)
	
	Escribir "Ingrese el numero de productos"
	leer cantidades(1)
	Escribir "Ingrese el costo de cada producto"
	para i <- 1 hasta cantidades(1) Hacer
		contproductos <- contproductos+1
		leer costoproducto
		preciototal <- preciototal+costoproducto
		si costoproducto > 1000 Entonces
			mayormil <- costoproducto
			contadormayormil <- contadormayormil+1
		FinSi
	FinPara
	Escribir "El precio total es de " preciototal
	Escribir "El número de productos que son mayores a $1000 son de " contadormayormil
FinAlgoritmo
