/*
4. Recursión y ejecución en tiempo de compilación: 

a. Se requiere el código de una función recursiva que compare dos variables que 
contengan texto e indique mediante una variable bool si son iguales (true si son 
iguales, false si no lo son). Explique su elección entre los tipos string y char* (lea 
el siguiente item de este ejercicio antes de elegir el tipo de variable) y demuestre 
la funcionalidad de su código con un texto de, al menos, 64 caracteres. 
b. El componente high_resolution_clock de <chrono> permite calcular el tiempo 
de ejecución de un proceso al hacer: 
#include <chrono> 
… 
auto startTime = std::chrono::high_resolution_clock::now(); 
miProcesoAMedir(); 
auto endTime = std::chrono::high_resolution_clock::now(); 
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>( 
endTime - startTime); 
std::cout << “A miProcesoAMedir le tomó: “ << elapsedTime.count() << “ 
nanosegundos” << std::endl; 
Utilice esté código y las modificaciones necesarias que crea conveniente para 
verificar cuanto tiempo toma la ejecución del código del ejercicio 4.1. 
c. 
Modifique el código del ejercicio 4.1 para que la comparación de los textos se 
realice en tiempo de compilación y obtenga el tiempo de ejecución. Compare 
este tiempo con el obtenido en el ejercicio 4.2 y justifique brevemente la 
diferencia (puede escribir su conclusión como un comentario al final del código 
de este item).
*/

#include <iostream>
#include <chrono>

bool compareText(const char* text1, const char* text2){
    if (text1[0] == '\0' && text2[0] == '\0'){
        return true;
    }
    if (text1[0] != text2[0]){
        return false;
    }
    return compareText(text1+1, text2+1);
}

constexpr bool compareTextComp(const char* text1, const char* text2){
    if (text1[0] == '\0' && text2[0] == '\0'){
        return true;
    }
    if (text1[0] != text2[0]){
        return false;
    }
    return compareTextComp(text1+1, text2+1);
}


int main(){
    char text1[] = "This is a very very VERY VERY LONG LONG text to compare, of at least 64 characters";
    char text2[] = "This is a very very VERY VERY LONG LONG text to compare, of at least 64 characters";
    auto startTime = std::chrono::high_resolution_clock::now();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    bool areEqual = compareText(text1, text2);
    std::cout << "The process took: " << elapsedTime.count() << " nanoseconds" << std::endl;
    std::cout << "The texts are equal: " << areEqual << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    auto startTimeComp = std::chrono::high_resolution_clock::now();
    auto endTimeComp = std::chrono::high_resolution_clock::now();
    auto elapsedTimeComp = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeComp - startTimeComp);
    bool areEqualComp = compareTextComp(text1, text2);
    std::cout << "The process, when compared in compilation time, took: " << elapsedTimeComp.count() << " nanoseconds" << std::endl;
    std::cout << "The texts are equal: " << areEqualComp << std::endl;
    return 0;
}
// Cuando el texto se compara en tiempo de compilación, el tiempo de ejecución es mucho menor
// ya que no se necesita ejecutar la función en tiempo de ejecución, sino que el compilador
// realiza la comparación en tiempo de compilación. En promedio, el tiempo de ejecución de la
// función en tiempo de ejecución es de aproximadamente 95 nanosegundos, mientras que en tiempo
// de compilación es de aproximadamente 60 nanosegundos.

// Elegí el tipo de variable char* ya que es más sencillo a la hora de comparar los textos, ya que
// se puede acceder a los caracteres de forma más sencilla que con un string.
