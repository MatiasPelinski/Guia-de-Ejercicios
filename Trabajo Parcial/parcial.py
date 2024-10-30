class Libro:
    def __init__(self, titulo, autor, anio_edicion, editorial, ISBN, num_paginas, reservado=False):
        self.titulo = titulo
        self.autor = autor
        self.anio_edicion = anio_edicion
        self.editorial = editorial
        self.ISBN = ISBN
        self.num_paginas = num_paginas
        self.reservado = reservado
        self.siguiente = None


class Lector:
    def __init__(self, nombre, dni, libro_solicitado):
        self.nombre = nombre
        self.dni = dni
        self.libro_solicitado = libro_solicitado
        self.siguiente = None


# Variables globales
cabeza = None  # Lista de libros
frente = None  # Inicio de la cola de lectores
final = None   # Final de la cola de lectores
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
                partes = linea.strip().split(',')
                if len(partes) == 6:
                    titulo, autor, anio_edicion, editorial, ISBN, num_paginas = partes
                    nuevo_libro = Libro(titulo, autor, int(anio_edicion), editorial, ISBN, int(num_paginas))
                    nuevo_libro.siguiente = cabeza
                    cabeza = nuevo_libro
    except IOError:
        print(f"Error: No se pudo abrir el archivo {nombre_archivo}")


def cargar_solicitudes_desde_archivo(nombre_archivo):
    global frente, final
    try:
        with open(nombre_archivo, 'r') as archivo:
            for linea in archivo:
                partes = linea.strip().split(',')
                if len(partes) == 3:
                    nombre, dni, libro = partes
                    nuevo_lector = Lector(nombre, dni, libro)
                    if frente is None:
                        frente = final = nuevo_lector
                    else:
                        final.siguiente = nuevo_lector
                        final = nuevo_lector
    except IOError:
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
        estado_reservado = " (Reservado)" if actual.reservado else ""
        print(f"Titulo: {actual.titulo}, Autor: {actual.autor}, Anio: {actual.anio_edicion}, "
              f"Editorial: {actual.editorial}, ISBN: {actual.ISBN}, Paginas: {actual.num_paginas}{estado_reservado}")
        actual = actual.siguiente


def eliminar_libro_del_archivo(libro_solicitado):
    lineas = []
    with open("biblioteca.txt", 'r') as archivo:
        lineas = archivo.readlines()

    with open("temp.txt", 'w') as temp:
        for linea in lineas:
            if libro_solicitado not in linea:
                temp.write(linea)

    import os
    os.remove("biblioteca.txt")
    os.rename("temp.txt", "biblioteca.txt")


def devolver_libro_al_archivo(libro_devuelto):
    with open("biblioteca.txt", 'a') as archivo:
        archivo.write(f"{libro_devuelto.titulo},{libro_devuelto.autor},{libro_devuelto.anio_edicion},"
                       f"{libro_devuelto.editorial},{libro_devuelto.ISBN},{libro_devuelto.num_paginas}\n")


def solicitar_libro(dni, nombre, libro):
    if not nombre or not dni:
        print("Error: Se necesita el nombre y el DNI para continuar.")
        return

    global frente, final
    actual = cabeza
    while actual:
        if actual.titulo == libro:
            if actual.reservado:
                print("Este libro ya fue reservado.")
                return
            actual.reservado = True  # Marcar como reservado
            eliminar_libro_del_archivo(libro)  # Eliminar libro de biblioteca.txt
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
    print(f"El libro {libro} no está disponible.")


def devolver_libro():
    global frente
    if frente is None:
        print("No hay solicitudes pendientes.")
        return
    print(f"{frente.nombre} ha devuelto el libro: {frente.libro_solicitado}")

    # Marcar el libro como disponible
    actual = cabeza
    while actual:
        if actual.titulo == frente.libro_solicitado:
            actual.reservado = False  # Desmarcar como reservado
            devolver_libro_al_archivo(actual)  # Agregar libro de nuevo a biblioteca.txt
            break
        actual = actual.siguiente

    agregar_historial(f"Devolver libro: {frente.libro_solicitado} por {frente.nombre}")
    temp = frente
    frente = frente.siguiente

    if frente:
        print(f"Atendiendo a: {frente.nombre} para el libro: {frente.libro_solicitado}")

    del temp


def mostrar_solicitudes():
    actual = frente
    if actual is None:
        print("No hay solicitudes pendientes.")
        return
    while actual:
        print(f"Solicitante: {actual.nombre}, DNI: {actual.dni}, Libro solicitado: {actual.libro_solicitado}")
        actual = actual.siguiente


def mostrar_historial():
    print("Historial de acciones:")
    for accion in historial:
        print(f"- {accion}")


def guardar_datos(nombre_archivo_libros, nombre_archivo_solicitudes):
    with open(nombre_archivo_libros, 'w') as archivo_libros:
        actual_libro = cabeza
        while actual_libro:
            archivo_libros.write(f"{actual_libro.titulo},{actual_libro.autor},{actual_libro.anio_edicion},"
                                 f"{actual_libro.editorial},{actual_libro.ISBN},{actual_libro.num_paginas}\n")
            actual_libro = actual_libro.siguiente

    with open(nombre_archivo_solicitudes, 'w') as archivo_solicitudes:
        actual_lector = frente
        while actual_lector:
            archivo_solicitudes.write(f"{actual_lector.nombre},{actual_lector.dni},{actual_lector.libro_solicitado}\n")
            actual_lector = actual_lector.siguiente

    agregar_historial("Guardar datos")
    print("Datos guardados en archivos.")


def quicksort(libros, izquierda, derecha):
    i = izquierda
    j = derecha
    pivote = libros[(izquierda + derecha) // 2].titulo

    while i <= j:
        while libros[i].titulo < pivote:
            i += 1
        while libros[j].titulo > pivote:
            j -= 1
        if i <= j:
            libros[i], libros[j] = libros[j], libros[i]
            i += 1
            j -= 1

    if izquierda < j:
        quicksort(libros, izquierda, j)
    if i < derecha:
        quicksort(libros, i, derecha)


def ordenar_libros():
    global cabeza
    libros = []
    actual = cabeza
    while actual:
        libros.append(actual)
        actual = actual.siguiente

    quicksort(libros, 0, len(libros) - 1)

    print("Libros ordenados por título:")
    for libro in libros:
        print(libro.titulo)


def busqueda_binaria(libros, titulo_buscado):
    izquierda = 0
    derecha = len(libros) - 1

    while izquierda <= derecha:
        medio = izquierda + (derecha - izquierda) // 2
        if libros[medio].titulo == titulo_buscado:
            return medio  # Título encontrado
        if libros[medio].titulo < titulo_buscado:
            izquierda = medio + 1
        else:
            derecha = medio - 1
    return -1  # Título no encontrado


def buscar_libro(titulo_buscado):
    global cabeza
    libros = []
    actual = cabeza
    while actual:
        libros.append(actual)
        actual = actual.siguiente

    resultado = busqueda_binaria(libros, titulo_buscado)
    if resultado != -1:
        print(f"Libro encontrado: {libros[resultado].titulo}")
    else:
        print(f"El libro {titulo_buscado} no se encuentra en la biblioteca.")


def main():
    cargar_libros_desde_archivo("biblioteca.txt")
    cargar_solicitudes_desde_archivo("solicitudes.txt")

    while True:
        print("\nMenú:")
        print("1. Agregar libro")
        print("2. Mostrar libros")
        print("3. Solicitar libro")
        print("4. Devolver libro")
        print("5. Mostrar solicitudes")
        print("6. Mostrar historial")
        print("7. Guardar datos")
        print("8. Ordenar libros")
        print("9. Buscar libro")
        print("0. Salir")

        opcion = input("Seleccione una opción: ")
        if opcion == '1':
            titulo = input("Título: ")
            autor = input("Autor: ")
            anio_edicion = int(input("Año de edición: "))
            editorial = input("Editorial: ")
            ISBN = input("ISBN: ")
            num_paginas = int(input("Número de páginas: "))
            agregar_libro(titulo, autor, anio_edicion, editorial, ISBN, num_paginas)
        elif opcion == '2':
            mostrar_libros()
        elif opcion == '3':
            nombre = input("Nombre del solicitante: ")
            dni = input("DNI del solicitante: ")
            libro = input("Título del libro solicitado: ")
            solicitar_libro(dni, nombre, libro)
        elif opcion == '4':
            devolver_libro()
        elif opcion == '5':
            mostrar_solicitudes()
        elif opcion == '6':
            mostrar_historial()
        elif opcion == '7':
            guardar_datos("biblioteca.txt", "solicitudes.txt")
        elif opcion == '8':
            ordenar_libros()
        elif opcion == '9':
            titulo_buscado = input("Título del libro a buscar: ")
            buscar_libro(titulo_buscado)
        elif opcion == '0':
            break
        else:
            print("Opción no válida.")


if __name__ == "__main__":
    main()

