Algoritmo Ejercicio7
	
	Dimension camiones(30)
	Dimension nombreapellido(30)
	Dimension horaegreso(30)
	Dimension yerba(30)
	Dimension madera(30)
	Dimension te(30)
	para i <- 0 Hasta camiones(30) Hacer
		Escribir "Ingrese la patente del camión"
			leer camiones(30)
			Escribir "Ingrese el nombre y apellido del camionero"
			leer nombreapellido(30)
		Escribir "Ingrese que tipo de carga lleva"
		Escribir "1-Madera"
		Escribir "2-Yerba"
		Escribir "3-Té"
			leer carga
				Segun  carga Hacer
					1:
						madera(30) <- carga
					2:
						yerba(30) <- carga
					3:
						te(30) <- carga
				FinSegun
		Escribir "Ingrese a que hora egresó de la planta"
		leer horaegreso(30)
	FinPara
	
	para i <- 1 hasta 30 Hacer
		Escribir "Patente del camión: " camiones(30)
		Escribir "Nombre y apellido del camionero: " nombreapellido(30)
		Escribir "Tipo de carga: " carga
		Escribir "Hora de egreso: " horaegreso(30)
	FinPara
	
	
	
	
	
	
	
	
	
FinAlgoritmo
