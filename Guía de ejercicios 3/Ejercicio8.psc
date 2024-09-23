Algoritmo Ejercicio8
	flag <- 0
	Escribir "Ingrese la cantidad de personas censadas"
	leer limitecenso
	
	para i <- 1 hasta limitecenso Hacer
		Escribir "Ingrese el numero de documento"
			leer numdoc
		Escribir "Ingrese el género de la persona"
		Escribir "1 - masculino"
		Escribir "2 - Femenino"
			leer generopersona
		Escribir "Ingrese la edad de la persona"
			leer edadpersona
			si flag == 0 Entonces
				maxedad <- edadpersona
				flag <- 1
			FinSi
			si edadpersona > maxedad Entonces
					maxedad <- edadpersona
			FinSi
					Segun generopersona Hacer
						1: 
							cantidadmasculino <- cantidadmasculino+1
							si edadpersona >= 16 y edadpersona <= 65 Entonces
								totaledad <- totaledad + 1
								
							FinSi
						2:
							cantidadfemenino<- cantidadfemenino+1
					FinSegun
				FinPara
				pocentajeedad <- totaledad/cantidadmasculino
	Escribir "La cantidad total de personas cesadas es de " limitecenso
	Escribir "La cantidad de varones es de " cantidadmasculino " y de mujeres " cantidadfemenino
	Escribir "El porcentaje de varones que tiene entre 16 y 65 es de " pocentajeedad*100 "%"
	Escribir "La persona con mayor edad tiene " maxedad
	
	
	
FinAlgoritmo
