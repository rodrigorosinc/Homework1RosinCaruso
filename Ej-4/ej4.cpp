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

constexpr bool compareTextCompiled(const char* text1, const char* text2){
    if (text1[0] == '\0' && text2[0] == '\0'){
        return true;
    }
    if (text1[0] != text2[0]){
        return false;
    }
    return compareTextCompiled(text1+1, text2+1);
}

bool compareTextString(const std::string text1, const std::string text2){
    if (text1[0] == '\0' && text2[0] == '\0'){
        return true;
    }
    if (text1[0] != text2[0]){
        return false;
    }
    return compareTextString(text1.substr(1), text2.substr(1));
}

int main(){
    // Creo los textos
    const char* text1 = "This is a very very VERY long long text to compare, to see if the function works correctly";
    const char* text2 = "This is a very very VERY long long text to compare, to see if the function works correctly";
    // Comparo los textos
    auto startTime = std::chrono::high_resolution_clock::now();
    bool result = compareText(text1, text2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    std::cout << "The function took: " << elapsedTime.count() << " nanoseconds" << std::endl;
    std::cout << "The texts are equal: " << result << std::endl;

    // Comparo los textos en tiempo de compilación
    auto startTimeCompiled = std::chrono::high_resolution_clock::now();
    bool resultCompiled = compareTextCompiled(text1, text2);
    auto endTimeCompiled = std::chrono::high_resolution_clock::now();
    auto elapsedTimeCompiled = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeCompiled - startTimeCompiled);
    std::cout << "The function took: " << elapsedTimeCompiled.count() << " nanoseconds" << std::endl;
    std::cout << "The texts are equal: " << resultCompiled << std::endl;

    // Comparo usando string
    std::string text3 = "This is a very very VERY long long text to compare, to see if the function works correctly";
    std::string text4 = "This is a very very VERY long long text to compare, to see if the function works correctly";
    auto startTimeString = std::chrono::high_resolution_clock::now();
    bool resultString = compareTextString(text3, text4);
    auto endTimeString = std::chrono::high_resolution_clock::now();
    auto elapsedTimeString = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeString - startTimeString);
    std::cout << "The function took: " << elapsedTimeString.count() << " nanoseconds" << std::endl;
    std::cout << "The texts are equal: " << resultString << std::endl;

    return 0;
}
// Cuando el texto se compara en tiempo de compilación, el tiempo de ejecución es mucho menor
// ya que no se necesita ejecutar la función en tiempo de ejecución, sino que el compilador
// realiza la comparación en tiempo de compilación. En promedio, el tiempo de ejecución de la
// función en tiempo de ejecución es de aproximadamente 95 nanosegundos, mientras que en tiempo
// de compilación es de aproximadamente 60 nanosegundos.

// Elegí el tipo de variable char* ya que es más sencillo a la hora de comparar los textos, ya que
// se puede acceder a los caracteres de forma más sencilla que con un string. Además, el tipo de
// char* 
