Aclaraciones sobre la compilación: 
    Cada archivo se puede compilar con la línea "estandar" o básica de compilación, 
    que es "g++ <nombre_del_archivo>.cpp -Wall -g -o <nombre_del_ejcutable>.exe".
    Para ejecutarlo lo mismo, se puede ejecutar con el ./<nombre_del_ejecutable>.
    
Dependiendo del ejercicio pueden pasar distintas cosas.
    Ej-1: Cuando se ejecuta, se pide al usuario que ingrese el tamaño n de la matriz,
    y esta es creada de tamaño nxn. Luego, se inicialiazan los valores y luego se imprimen
    por terminal de la forma solicitada en la consigna.
    
    Ej-2: Cuando se ejecuta, se crea el archivo y, si el usuario desea, se escriben
    ejemplos de cada prioridad que verifican el fucionamiento del sitema de logeo,
    que están hardcodeados. Una vez hecho esto, el prorgama pide al usuario ingresar
    una prioridad para ingresar un mensaje nuevo, donde el mensaje es escrito por el usuario. 
    Una vez seleccionada (y dependiendo de la misma) el programa pide por otras distintas 
    variables. Por ejemplo, si se selecciona 4 (que representa a ERROR), el programa 
    pregunta por el tipo de error a loguear, el nombre del archivo donde ocurrió y la línea. 
    Si se selecciona info, se pide solo por un mensaje, y así. 
    Una vez loguado lo que se necesite, se pregunta al usuario si quiere tirar un error.
    Si se selecciona que si, se tira el error, se loguea en el sistema y se corta la ejecución.
    Si se selecciona que no, simplemente termina la ejecución del código
    
    El código además cuando pide por la prioridad y uno ingresa un parámetro no deseado, tira
    un error y termina la ejecución del mismo.

    Ej-3: Cuando se ejecuta se imprime en pantalla un ejemplo de uso de la lista. Donde se atacan
    la mayoría de casos de para el insert, erase y las otras funciones. Primero se insertan los elementos
    y luego se borran. Cuando se borra el último, termina la ejecución del código.

    Ej-4:  
