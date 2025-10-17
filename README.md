# Algoritmos y Complejidad

## Descripción

Repositorio académico del curso de Algoritmos y Complejidad, que contiene implementaciones clásicas de algoritmos fundamentales en lenguaje C y ejercicios prácticos para el análisis de eficiencia y complejidad computacional.

## Algoritmos Principales Incluidos

### Algoritmos de Ordenamiento
- **Insertion Sort** (Insercion.c) - Ordenamiento por inserción
- **Selection Sort** (Seleccion.c) - Ordenamiento por selección
- **Merge Sort** (Mergesort.c, p2-ms_t5.c, p5-merge_t4.c) - Ordenamiento por mezcla
- **Quick Sort** (Quicksort.c) - Ordenamiento rápido
- **Sorting** (sorting.c) - Métodos de ordenamiento adicionales

### Algoritmos de Búsqueda
- **Sequential Search** (seqsearch.c) - Búsqueda secuencial
- **Binary Search** (binsearch.c, p2-binsearch_t4.c, p4-binsearch_t4.c) - Búsqueda binaria

### Algoritmos de División y Conquista
- **Torres de Hanoi** (p7-torres_t4.c) - Problema clásico recursivo
- **Coeficiente Binomial** (cofbinomial.c) - Cálculo de coeficientes binomiales

### Métodos y Ejercicios
- **Métodos 1-4** (metodo1.c, metodo2.c, metodo3.c, metodo4.c) - Ejercicios de análisis de complejidad
- **Series T6** (t6p1.c, t6p2.c, t6p3.c, t6p4.c) - Tarea 6: ejercicios de programación
- **Series T7** (t7p1.c, t7p2.c, t7p2d.c, t7p3.c) - Tarea 7: ejercicios avanzados

## Estructura de Archivos

```
Algoritmos-y-Complejidad/
│
├── .vscode/               # Configuración del entorno de desarrollo
├── .gitignore             # Archivos ignorados por Git
├── README.md              # Este archivo
│
├── Ordenamiento:
│   ├── Insercion.c
│   ├── Seleccion.c
│   ├── Mergesort.c
│   ├── Quicksort.c
│   └── sorting.c
│
├── Búsqueda:
│   ├── binsearch.c
│   └── seqsearch.c
│
├── Prácticas y Tareas:
│   ├── p2-p7 (archivos .c y ejecutables)
│   ├── t6p1-t6p4 (Tarea 6)
│   └── t7p1-t7p3 (Tarea 7)
│
└── Otros:
    ├── cofbinomial.c
    ├── main.c, maini.c
    └── metodo1-4.c
```

## Requerimientos para Compilar

### Software Necesario
- **Compilador GCC** (GNU Compiler Collection) versión 4.8 o superior
- **Sistema Operativo**: Linux, macOS o Windows (con MinGW/Cygwin)
- **Make** (opcional, para automatización de compilación)

### Instalación de GCC

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get update
sudo apt-get install build-essential
```

**macOS:**
```bash
xcode-select --install
```

**Windows:**
Descargar e instalar MinGW desde [mingw.org](http://www.mingw.org/)

## Cómo Usar

### Compilación Individual

Para compilar cualquier archivo .c:

```bash
gcc -o nombre_ejecutable archivo.c
```

**Ejemplos:**

```bash
# Compilar el algoritmo de Merge Sort
gcc -o mergesort Mergesort.c

# Compilar el algoritmo de búsqueda binaria
gcc -o binsearch binsearch.c

# Compilar Torres de Hanoi
gcc -o torres p7-torres_t4.c
```

### Ejecución

Después de compilar, ejecutar el programa:

```bash
# Linux/macOS
./nombre_ejecutable

# Windows
nombre_ejecutable.exe
```

### Compilación con Opciones de Optimización

Para análisis de rendimiento:

```bash
# Sin optimización (para depuración)
gcc -O0 -g -o programa archivo.c

# Con optimización estándar
gcc -O2 -o programa archivo.c

# Con optimización máxima
gcc -O3 -o programa archivo.c
```

### Notas de Uso

- La mayoría de los programas aceptan entrada por teclado o generan datos aleatorios
- Algunos archivos incluyen funciones de medición de tiempo para análisis de complejidad
- Los archivos ejecutables sin extensión (p2, p4, p5, etc.) son binarios compilados previamente

## Temas Cubiertos

- Análisis de complejidad temporal (Big O, Ω, Θ)
- Algoritmos de ordenamiento: comparativos y no comparativos
- Técnicas de diseño: división y conquista, programación dinámica
- Algoritmos de búsqueda en estructuras ordenadas
- Recurrencias y ecuaciones de recurrencia
- Análisis empírico vs teórico

## Créditos

**Autor:** Sebastián de Jesús Hernández  
**Curso:** Algoritmos y Complejidad  
**Periodo:** Primer Parcial  
**Lenguaje:** C (C Standard)  
**Institución:** Material académico  

## Licencia

Este repositorio contiene material académico con fines educativos.

---

Última actualización: Octubre 2024
