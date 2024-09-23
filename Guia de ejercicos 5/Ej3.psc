Proceso PromedioNotasAlumnos
    Definir notas Como Real
    Definir promedio Como Real
	Dimension notas[40,5]
    
    Para i = 1 Hasta 40 Con Paso 1
        Para j = 1 Hasta 5 Con Paso 1
            Escribir "Ingrese la nota ", j, " del alumno ", i
            Leer notas[i, j]
        FinPara
    FinPara
	
    
    Para i = 1 Hasta 40 Con Paso 1
        promedio = 0
        Para j = 1 Hasta 5 Con Paso 1
            promedio = promedio + notas[i, j]
        FinPara
        promedio = promedio / 5
        Escribir "El promedio del alumno ", i, " es: ", promedio
    FinPara
FinProceso

