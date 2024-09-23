Algoritmo Ejercicio1
	definir repositor,cajero,supervisor,puesto como real;
	repositor <- 32335
	cajero <- 38630.89
	supervisor <- 45560.20
	
	escribir "Eliga el puesto que le corresponde"
	Escribir "1-repositor"
	Escribir "2-cajero"
	Escribir "3-supervisor"
	leer puesto 
	
	Segun puesto Hacer
		1:
			deducciones <- (11*repositor)/100
			obra_social <- (3*repositor)/100
			bono <- (8*repositor)/100
		Escribir "Del sueldo neto del repositor, que es de 32335, a las deducciones(11%) le corresponde " deducciones " y a la obra social " obra_social " ademas, posee un bono de compra de " bono
		2:
			deducciones <- (11*cajero)/100
			obra_social <- (3*cajero)/100
			bono <- (8*repositor)/100
		Escribir "Del sueldo neto del cajero, que es de 38630.89, a las deducciones(11%) le corresponde " deducciones " y a la obra social(3%) " obra_social " ademas, posee un bono de compra de " bono 
		3:
			deducciones <- (11*supervisor)/100
			obra_social <- (3*supervisor)/100
			bono <- (8*supervisor)/100
		Escribir "Del sueldo neto del supervisor, que es de 45560.20, a las deducciones(11%) le corresponde " deducciones " y a la obra social(3%) " obra_social " ademas, posee un bono de " bono
	Fin Segun

	
FinAlgoritmo
