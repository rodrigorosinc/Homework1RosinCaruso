# README

## Aclaraciones sobre la compilación
Cada archivo se puede compilar con la línea estándar de compilación:

```sh
g++ <nombre_del_archivo>.cpp -Wall -g -o <nombre_del_ejecutable>.exe
```

Para ejecutarlo:

```sh
./<nombre_del_ejecutable>
```

Dependiendo del ejercicio, pueden ocurrir distintas cosas.

---

## Ejercicios

### Ejercicio 1
Cuando se ejecuta:
1. Se pide al usuario que ingrese el tamaño `n` de la matriz.
2. Se crea una matriz de tamaño `n x n`.
3. Se inicializan los valores.
4. Se imprimen por terminal de menor a mayor, según la consigna.

---

### Ejercicio 2
Cuando se ejecuta:
1. Se crea un archivo de log.
2. Si el usuario lo desea, se escriben ejemplos de cada prioridad hardcodeados.
3. Luego, se pide al usuario ingresar una prioridad para un nuevo mensaje.
4. Dependiendo de la prioridad, se solicitan diferentes datos adicionales:
   - **Error (4)**: Se pide tipo de error, nombre del archivo y línea.
   - **Security (6)**: Se pide el nombre de usuario y se loguea en si el acceso fue concedido
   - **Las demás**: Solo se solicita el mensaje.
5. Una vez logueado, se pregunta al usuario si desea lanzar un error:
   - **Si elige sí**: Se registra el error y se finaliza la ejecución.
   - **Si elige no**: Termina la ejecución sin errores.

Tener en cuanta que si se ingresa una prioridad no válida, se lanza un error, se registra y se finaliza la ejecución.

> **Nota:** Implementar la `main` como un menú mejora la flexibilidad para que el usuario pueda decidir qué mensaje loguear y con qué prioridad. 

---

### Ejercicio 3
Cuando se ejecuta:
1. Se muestra en pantalla un ejemplo de uso de la lista.
2. Se prueban los casos principales de `insert`, `erase`, y del `push_back` y `push_front`.
3. Primero se insertan elementos y luego se eliminan.
4. Cuando se borra el último elemento, el programa finaliza.

Todo el proceso es impreso por la funcion `print_list`
> **Elección de `shared_ptr`**: Permite mantener un puntero al `tail` de la lista, facilitando la inserción de nodos al final sin necesidad de recorrer la lista completa.

---

### Ejercicio 4
Cuando se ejecuta:
1. Se imprimen los tiempos de ejecución de las comparaciones de texto.
2. **Sin `constexpr`**: La ejecución tarda más.
3. **Con `constexpr`**: La ejecución es mucho más rápida, ya que la comparación se realiza en tiempo de compilación.

> **Elección de `char*` sobre `std::string`**: Se explica en los comentarios debajo del `main`, pero en resumen:
> - `char*` permite el uso de `constexpr`, mientras que `std::string` no.
> - `std::string` maneja memoria dinámica, lo que impide su evaluación en tiempo de compilación.
> - `char*` permite optimizaciones del compilador para reducir los costos de ejecución.

---

