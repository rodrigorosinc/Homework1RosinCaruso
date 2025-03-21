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

    std::cout << std::endl;
    // Comparo los textos en tiempo de compilación
    constexpr const char* text1c = "This is a very very VERY long long text to compare, to see if the function works correctly";
    constexpr const char* text2c = "This is a very very VERY long long text to compare, to see if the function works correctly";
    auto startTimeCompiled = std::chrono::high_resolution_clock::now();
    bool resultCompiled = compareTextCompiled(text1c, text2c);
    auto endTimeCompiled = std::chrono::high_resolution_clock::now();
    auto elapsedTimeCompiled = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeCompiled - startTimeCompiled);
    std::cout << "The function that compares on compile time took: " << elapsedTimeCompiled.count() << " nanoseconds" << std::endl;
    std::cout << "The texts are equal: " << resultCompiled << std::endl;
    return 0;
}
// Cuando el texto se compara en tiempo de compilación, la función no se ejecuta en tiempo de ejecución, 
// sino que el compilador evalúa la expresion y reemplaza el resultado directamente en el código compilado. 
// Por esto, el tiempo de ejecución es mucho menor, en comparación con una evaluación en tiempo de ejecución, 
// ya que es eliminado cualquier costo de ejecución.

// Elegí el tipo de variable char* porque permite acceder a los caracteres de forma directa y es compatible
// con el constexpr. std::string, en cambio no es compatible con el constexpr ya que maneja memoria dinámica internamente.
// Al usar char*, el compilador puede evaluar la comparación en tiempo de compilación y optimizar el código resultante. 

// Es por eso que resulta más conveniente usar char*.

