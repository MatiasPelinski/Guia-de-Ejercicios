Algoritmo Ejercicio4
	Definir DNI,categoria,Maestranza,Gerencia,Administracion como real;
	
	Maestranza<- 23600
	Administracion <- 35800
	Gerencia <- 60420
	
	escribir "Eliga la categoria que le corresponde"
	Escribir "1-Maestranza"
	Escribir "2-Administracion"
	Escribir "3-Gerencia"
	leer categoria
	
	
	Segun categoria Hacer
		1:
			deducciones <- (11*Maestranza)/100
			obra_social <- (3*Maestranza)/100
			 
			Escribir "Del sueldo neto del maestranza, que es de 23600, a las jubilaciones(11%) le corresponde " deducciones " y a la obra social " obra_social 
		2:
			deducciones <- (11*Administracion)/100
			obra_social <- (3*Administracion)/100
			 
			Escribir "Del sueldo neto del cajero, que es de 38630.89, a las deducciones(11%) le corresponde " deducciones " y a la obra social(3%) " obra_social 
		3:
			deducciones <- (11*Gerencia)/100
			obra_social <- (3*Gerencia)/100
			 
			Escribir "Del sueldo neto del supervisor, que es de 45560.20, a las deducciones(11%) le corresponde " deducciones " y a la obra social(3%) " obra_social 
	FinSegun
	
FinAlgoritmo
