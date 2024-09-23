Algoritmo Ejercicio3
	Definir  Preciokg, cantidadkg1,cantidadkg2,cantidadkg3, total como reales;
	
	Escribir "Defina el precio por kg del producto"
	leer Preciokg
	Escribir "Defina la cantidad en kg de los 3 productos" 
	leer cantidadkg1,cantidadkg2,cantidadkg3
	
	cantidadkg1 <- (cantidadkg1*Preciokg)/1
	cantidadkg2 <- (cantidadkg2*Preciokg)/1
	cantidadkg3 <- (cantidadkg3*Preciokg)/1
	total <- cantidadkg1+cantidadkg2+cantidadkg3
	
	
	si total > 100 Entonces
		descuento <- (10*total)/100
		totaldescuento <- total-descuento
		Escribir "Se le hizo un descuento. Del monto total, que es de " total " Ahora el nuevo monto a pagar es de " totaldescuento
	sino 
		Escribir  "Cada producto te va a costar " cantidadkg1 ", " cantidadkg2 " y " cantidadkg3 
		Escribir  "El total de pesos de la compra realizada es de " total
	FinSi
	
	
	
	
	
FinAlgoritmo
