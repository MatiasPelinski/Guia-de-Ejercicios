Algoritmo Ejercicio4
	definir DNI como entero; 
	
	para servicio <-1 Hasta 5 con paso 1 Hacer
		Escribir "Ingrese su DNI"
			leer dni 
		Escribir "Ingrese el tipo de servicio que desee"
		Escribir "1- Internet 30 Megas"
		Escribir "2- Internet 50 Megas"
		Escribir "3- Internet 100 Megas"
			leer servicio
		Segun servicio Hacer
			1:
				Escribir "El servicio que eligió el DNI " DNI " eligió el servicio de internet de 30 Megas y tiene un coste de $750"
			2:
				Escribir "El servicio que eligió el DNI " DNI " eligió el servicio de internet de 50 Megas y tiene un coste de $1100 " 
			3:
				descuento <- (5*1500)/100
				totaldescuento <- 1500-descuento
				Escribir "El servicio que eligió el DNI " DNI " eligió el servicio de internet de 100 Megas y tiene un coste de $1500, ademas tiene un descuento del 5%, que lo deja en " totaldescuento
		Fin Segun
	FinPara
	


FinAlgoritmo

