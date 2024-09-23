	Algoritmo VentasMayorista
		
		Dimension CANT(50, 15)
		Dimension TOTAL(15)
		
		
		i <- 0
		j <- 0
		mayorVenta <- 0
		vendedorMayor <- 0
		
		
		Para j <- 1 Hasta 15 Con Paso 1 Hacer
			TOTAL[j] <- 0
		FinPara
		
		
		Para i <- 1 Hasta 50 Con Paso 1 Hacer
			Para j <- 1 Hasta 15 Con Paso 1 Hacer
				Escribir "Ingrese la cantidad del articulo ", i, " vendida por el vendedor ", j, ": "
				Leer CANT[i, j]
			FinPara
		FinPara
		
		
		Para j <- 1 Hasta 15 Con Paso 1 Hacer
			Para i <- 1 Hasta 50 Con Paso 1 Hacer
				TOTAL[j] <- TOTAL[j] + CANT[i, j]
			FinPara
		FinPara
		
		
		mayorVenta <- TOTAL[1]
		vendedorMayor <- 1
		Para j <- 2 Hasta 15 Con Paso 1 Hacer
			Si TOTAL[j] > mayorVenta Entonces
				mayorVenta <- TOTAL[j]
				vendedorMayor <- j
			FinSi
		FinPara
		
		
		Escribir "El vendedor que realizó la mayor venta es el vendedor ", vendedorMayor, " con ", mayorVenta, " artículos vendidos."
		
FinAlgoritmo

	

