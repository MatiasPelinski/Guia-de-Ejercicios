Algoritmo NotasAlumnos
    
    Dimension notas(4, 4)
	
    suma <- 0
    i <- 0
    j <- 0
	
    Para i <- 1 Hasta 4 Con Paso 1 Hacer
        suma <- 0
        Escribir "Ingrese las notas del alumno ", i, ":"
        Para j <- 1 Hasta 3 Con Paso 1 Hacer
            Escribir "Nota ", j, ": "
            Leer notas[i, j]
            suma <- suma + notas[i, j]  
        FinPara
        
       
        notas[i, 4] <- suma / 3
    FinPara
	
   
    Escribir "Notas y promedios de cada alumno:"
    Para i <- 1 Hasta 4 Con Paso 1 Hacer
        Escribir "Alumno ", i, ":"
        Para j <- 1 Hasta 3 Con Paso 1 Hacer
            Escribir "Nota ", j, ": ", notas[i, j]
        FinPara
        Escribir "Promedio: ", notas[i, 4]
    FinPara
	
FinAlgoritmo

