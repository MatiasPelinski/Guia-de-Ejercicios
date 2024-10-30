class Libro:
    def __init__(self, titulo, autor, anio_edicion, editorial, ISBN, num_paginas):
        self.titulo = titulo
        self.autor = autor
        self.anio_edicion = anio_edicion
        self.editorial = editorial
        self.ISBN = ISBN
        self.num_paginas = num_paginas
        self.siguiente = None

class Lector:
    def __init__(self, nombre, dni, libro_solicitado):
        self.nombre = nombre
        self.dni = dni
        self.libro_solicitado = libro_solicitado
        self.siguiente = None

cabeza = None
frente = None
final = None
historial = []
MAX_HISTORIAL = 100

def agregar_historial(accion):
    if len(historial) < MAX_HISTORIAL:
        historial.append(accion)

def cargar_libros_desde_archivo(nombre_archivo):
    global cabeza
    try:
        with open(nombre_archivo, 'r') as archivo:
            for linea in archivo:
                datos = linea.strip().split(',')
                if len(datos) == 6:
                    titulo, autor, anio_edicion, editorial, ISBN, num_paginas = datos
                    nuevo_libro = Libro(titulo, autor, int(anio_edicion), editorial, ISBN, int(num_paginas))
                    nuevo_libro.siguiente = cabeza
                    cabeza = nuevo_libro
    except FileNotFoundError:
        print(f"Error: No se pudo abrir el archivo {nombre_archivo}")

def agregar_libro(titulo, autor, anio_edicion, editorial, ISBN, num_paginas):
    global cabeza
    nuevo_libro = Libro(titulo, autor, anio_edicion, editorial, ISBN, num_paginas)
    nuevo_libro.siguiente = cabeza
    cabeza = nuevo_libro
    agregar_historial(f"Agregar libro: {titulo}")

def mostrar_libros():
    if cabeza is None:
        print("No hay libros en la biblioteca.")
        return
    actual = cabeza
    while actual:
        print(f"Titulo: {actual.titulo}, Autor: {actual.autor}, Anio: {actual.anio_edicion}, "
              f"Editorial: {actual.editorial}, ISBN: {actual.ISBN}, Paginas: {actual.num_paginas}")
        actual = actual.siguiente

def ordenar_libros():
    global cabeza
    if cabeza is None or cabeza.siguiente is None:
        print("No hay suficientes libros para ordenar.")
        return

    intercambiado = True
    while intercambiado:
        intercambiado = False
        actual = cabeza
        anterior = None
        siguiente = cabeza.siguiente

        while siguiente:
            if actual.titulo > siguiente.titulo:
                actual.siguiente = siguiente.siguiente
                siguiente.siguiente = actual

                if anterior:
                    anterior.siguiente = siguiente
                else:
                    cabeza = siguiente

                intercambiado = True
                anterior = siguiente
                siguiente = actual.siguiente
            else:
                anterior = actual
                actual = siguiente
                siguiente = siguiente.siguiente
    print("Libros ordenados por titulo.")

def eliminar_libro_de_lista(libro_solicitado):
    global cabeza
    actual = cabeza
    anterior = None

    while actual:
        if actual.titulo == libro_solicitado:
            if anterior:
                anterior.siguiente = actual.siguiente
            else:
                cabeza = actual.siguiente
            del actual
            return
        anterior = actual
        actual = actual.siguiente

def eliminar_libro_del_archivo(libro_solicitado):
    with open("biblioteca.txt", "r") as archivo:
        lineas = archivo.readlines()

    with open("temp.txt", "w") as temp:
        for linea in lineas:
            if not linea.startswith(libro_solicitado + ','):
                temp.write(linea)

    import os
    os.remove("biblioteca.txt")
    os.rename("temp.txt", "biblioteca.txt")

def verificar_dni(dni):
    actual = frente
    while actual:
        if actual.dni == dni:
            return True
        actual = actual.siguiente
    return False

def solicitar_libro(dni, nombre, libro):
    global frente, final
    if not nombre or not dni:
        print("Error: Se necesita el nombre y el DNI para continuar.")
        return

    actual = cabeza
    while actual:
        if actual.titulo == libro:
            eliminar_libro_de_lista(libro)
            eliminar_libro_del_archivo(libro)
            nuevo_lector = Lector(nombre, dni, libro)
            if frente is None:
                frente = final = nuevo_lector
            else:
                final.siguiente = nuevo_lector
                final = nuevo_lector
            print(f"{nombre} ha solicitado el libro: {libro}")
            agregar_historial(f"Solicitar libro: {libro} por {nombre}")
            return
        actual = actual.siguiente
    print(f"El libro {libro} no esta disponible.")

def devolver_libro(libro):
    global frente, final, cabeza  # Agregar 'cabeza' aquí
    actual = frente
    anterior = None

    while actual:
        if actual.libro_solicitado == libro:
            if anterior:
                anterior.siguiente = actual.siguiente
            else:
                frente = actual.siguiente
            if actual == final:
                final = anterior
            del actual

            nuevo_libro = Libro(libro, "", 0, "", "", 0)
            nuevo_libro.siguiente = cabeza
            cabeza = nuevo_libro
            agregar_historial(f"Devolver libro: {libro}")

            with open("biblioteca.txt", "a") as archivo:
                archivo.write(f"{libro},,,0,,0\n")

            print(f"Libro devuelto: {libro}")
            return
        anterior = actual
        actual = actual.siguiente
    print("El libro no está en solicitudes.")

def mostrar_solicitudes():
    actual = frente
    if actual is None:
        print("No hay solicitudes de libros.")
    else:
        while actual:
            print(f"Nombre: {actual.nombre}, DNI: {actual.dni}, Libro solicitado: {actual.libro_solicitado}")
            actual = actual.siguiente

def buscar_libro(titulo):
    actual = cabeza
    while actual:
        if actual.titulo == titulo:
            print(f"Libro encontrado:\nTitulo: {actual.titulo}, Autor: {actual.autor}, "
                  f"Anio: {actual.anio_edicion}, Editorial: {actual.editorial}, "
                  f"ISBN: {actual.ISBN}, Paginas: {actual.num_paginas}")
            return
        actual = actual.siguiente
    print("Libro no encontrado.")

def mostrar_historial():
    if len(historial) == 0:
        print("No hay acciones en el historial.")
    else:
        print("Historial de acciones:")
        for accion in historial:
            print(accion)

def guardar_solicitudes():
    with open("solicitudes.txt", "w") as archivo_solicitudes:
        actual = frente
        while actual:
            archivo_solicitudes.write(f"Nombre: {actual.nombre}, DNI: {actual.dni}, Libro solicitado: {actual.libro_solicitado}\n")
            actual = actual.siguiente

def guardar_datos(nombre_archivo_libros):
    with open(nombre_archivo_libros, "w") as archivo_libros:
        actual_libro = cabeza
        while actual_libro:
            archivo_libros.write(f"{actual_libro.titulo},{actual_libro.autor},{actual_libro.anio_edicion},"
                                 f"{actual_libro.editorial},{actual_libro.ISBN},{actual_libro.num_paginas}\n")
            actual_libro = actual_libro.siguiente
    guardar_solicitudes()
    agregar_historial("Guardar datos")
    print("Datos guardados en archivos.")

def main():
    cargar_libros_desde_archivo("biblioteca.txt")
    while True:
        print("\n--- Menu ---")
        print("1. Agregar libro")
        print("2. Mostrar libros")
        print("3. Ordenar libros por titulo")
        print("4. Solicitar libro")
        print("5. Devolver libro")
        print("6. Mostrar solicitudes")
        print("7. Buscar libro")
        print("8. Mostrar historial")
        print("9. Guardar datos")
        print("0. Salir")
        opcion = int(input("Seleccione una opcion: "))

        if opcion == 1:
            titulo = input("Ingrese titulo: ")
            autor = input("Ingrese autor: ")
            anio_edicion = int(input("Ingrese anio de edicion: "))
            editorial = input("Ingrese editorial: ")
            ISBN = input("Ingrese ISBN: ")
            num_paginas = int(input("Ingrese numero de paginas: "))
            agregar_libro(titulo, autor, anio_edicion, editorial, ISBN, num_paginas)
        elif opcion == 2:
            mostrar_libros()
        elif opcion == 3:
            ordenar_libros()
        elif opcion == 4:
            dni = input("Ingrese DNI del solicitante: ")
            nombre = input("Ingrese nombre del solicitante: ")
            libro = input("Ingrese libro solicitado: ")
            solicitar_libro(dni, nombre, libro)
        elif opcion == 5:
            libro = input("Ingrese el titulo del libro a devolver: ")
            devolver_libro(libro)
        elif opcion == 6:
            mostrar_solicitudes()
        elif opcion == 7:
            titulo = input("Ingrese el titulo del libro a buscar: ")
            buscar_libro(titulo)
        elif opcion == 8:
            mostrar_historial()
        elif opcion == 9:
            guardar_datos("biblioteca.txt")
        elif opcion == 0:
            break
        else:
            print("Opcion no valida.")

if __name__ == "__main__":
    main()
