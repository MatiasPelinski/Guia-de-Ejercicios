Algoritmo Ejercicio5
	definir vendedores,ventas,totalventas,mayorventa,menorventa,numvendedor1,numvendedor2,contadorvendedores Como Entero
	Definir cambiopesos Como Real
	maximo <- 15
	flag1 <- 0
	flag2 <- 0
	Dimension vendedores(15)
	Dimension ventas(15)
	
	para i <- 1 Hasta 15 Hacer
		ventas(15) <- azar(maximo+1)  //Darle un valor al azar a las ventas
		Escribir ventas(15)
		totalventas <- totalventas+ventas(15)
		contadorvendedores <- contadorvendedores+1
		vendedores(15) <- contadorvendedores
			si flag1 = 0 Entonces
				mayorventa <- ventas(15)
				flag1 <- 1 
			FinSi
			si ventas(15) > mayorventa Entonces
				mayorventa <- ventas(15)			//Si el  nuevo valor de venta es mayor al ultimo valor de venta, entonces va a tomar el nuevo valor, y ademas va a guardar el numero del vendedor"
				numvendedor1 <- contadorvendedores
			FinSi
			si flag2 = 0 Entonces
				menorventa <- ventas(15)
				flag2 <- 1 
			FinSi
			si ventas(15) < menorventa Entonces
				menorventa <- ventas(15)
				numvendedor2 <- contadorvendedores
			FinSi
		FinPara
		
	cambiopesos <- totalventas*140
	
	Escribir "El vendedor " numvendedor1 " tuvo la mayor venta que fue de " mayorventa
	Escribir "El vendedor " numvendedor2 " tuvo la menor venta que fue de " menorventa
	Escribir "El total de ventas en dolares, que fue de " totalventas " al cambio en pesos, nos queda en" cambiopesos " pesos."
	
FinAlgoritmo
