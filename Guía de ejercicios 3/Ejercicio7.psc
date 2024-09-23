Algoritmo Ejercicio7
	Escribir "Ingrese la cantidad total de socios"
	leer totalsocios
	
	para totalsocios <- 1 hasta totalsocios Con Paso 1 hacer
		Escribir "Ingrese el número de socio"
			leer numsocio 
		Escribir "Ingrese su edad" 
			leer edadsocio 
		Escribir "Ingrese que tipo de deporte practica"
		Escribir "1 - Tenis"
		Escribir "2 - Rugby"
		Escribir "3 - Voley"
		Escribir "4 - Hockey"
		Escribir "5 - Futbol"
			leer deporte
				Segun deporte Hacer
						1:
							contadortenis<- contadortenis+1
							totaledadtenis <- (totaledadtenis + edadsocio)/contadortenis
						2:
							contadorrugby<- contadorrugby+1
							totaledadrugby <- (totaledadrugby + edadsocio)/contadortenis
						3:
							contadorvoley<- contadorvoley+1
							totaledadvoley <- (totaledadvoley + edadsocio)/contadorvoley
						4: 
							contadorhockey<- contadorhockey+1
							totaledadhockey <- (totaledadhockey + edadsocio)/contadorhockey
						5:
							contadorfutbol <- contadorfutbol+1
							totaledadfutbol <- (totaledadfutbol+edadsocio)/contadorfutbol
				Fin Segun
		
			FinPara
			
			Escribir "El número de socios que practican tenis son " contadortenis " y los que practican futbol son " contadorfutbol	
			Escribir "El promedio de edad de los que practican tenis es de " totaledadtenis
			Escribir "El promedio de edad de los que practican rugby es de " totaledadrugby
			Escribir "El promedio de edad de los que practican voley es de " totaledadvoley
			Escribir "El promedio de edad de los que practican hockey es de " totaledadhockey
			Escribir "El promedio de edad de los que practican futbol es de " totaledadfutbol
FinAlgoritmo
