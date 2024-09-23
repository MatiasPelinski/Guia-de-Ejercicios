Algoritmo SueldosEmpleados
   
    Dimension sueldos(10)
    
  
    mayorSueldo <- 0
    i <- 1
	
    Para i <- 1 Hasta 10 Con Paso 1 Hacer
        Escribir "Ingrese el sueldo del empleado ", i, ": "
        Leer sueldos[i]
    FinPara
	
    Escribir "Sueldos ingresados: "
    Para i <- 1 Hasta 10 Con Paso 1 Hacer
        Escribir "Empleado ", i, ": $", sueldos[i]
    FinPara
	
    mayorSueldo <- sueldos[1]
    Para i <- 2 Hasta 10 Con Paso 1 Hacer
        Si sueldos[i] > mayorSueldo Entonces
            mayorSueldo <- sueldos[i]
        FinSi
    FinPara
	
    Escribir "El mayor sueldo es: $", mayorSueldo
FinAlgoritmo

