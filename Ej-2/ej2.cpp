/*
2. En muchos sistemas, es importante registrar todo lo que sucede mientras están en 
funcionamiento. Para ello, se utiliza un sistema de log que almacena los eventos 
relevantes. Cada evento recibe una etiqueta que indica su nivel de importancia o 
gravedad. Las etiquetas más comunes son: DEBUG, INFO, WARNING, ERROR y 
CRITICAL. 
a. En este ejercicio, se pide crear un sistema log que permite agregar entradas a un 
archivo mediante el llamado a una función logMessage definida en pseudo código de 
la siguiente manera: 
 
void logMessage(String mensaje, Integer/Otro NivelSeveridad) 
 
Donde NivelSeveridad corresponderá con unas de las leyendas previamente 
mencionadas. El formato esperado en una línea del archivo de log es el siguiente: 
Homework #1  
I102 – Paradigmas de Programación 
[ERROR] <Mensaje> 
[INFO] <Mensaje> 
etc. 
Verifique su funcionamiento con al menos una entrada de cada tipo. 
b. En un proyecto usualmente se solicitan cambios para mejorar o agregar funcionalidad. 
Para el caso del código del ejercicio 2.a, se requiere tener la habilidad de agregar 
mensajes personalizados para registrar otro tipo de eventos. Los requisitos son los 
siguientes: 
i. 
    Todos los nuevos mensajes deben ser invocados con logMessage. 
ii. 
    Se requiere la posibilidad de registrar errores, indicando el mensaje de error, el 
    archivo y la línea de código donde sucedió este error, es decir: 
    logMessage(String Mensage_de_Error, String Archivo, Int Línea_de_Código) 
iii. 
    Se requiere la posibilidad de registrar un mensaje de “Acceso de Usuario” a la 
    aplicación. Este mensaje debe tener una leyenda nueva: [SECURITY]. La misma 
    debe ser ingresada de la siguiente manera: 
    logMessage(String Mensaje_De_Acceso, String Nombre_de_Usuario) 
    Los mensajes de acceso pueden ser: Access Granted, Access Denied, etc. 
iv. 
    Se requiere un código que pruebe que el sistema verifica la funcionalidad 
    requerida y que además demuestre que puede capturar un error en runtime, 
    crear una entrada en el log y después detener la ejecución del programa y salir 
    del mismo con un código de error (return 1).  

*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Priority{
    DEBUG = 1,
    INFO = 2,
    WARNING = 3,
    ERROR = 4,
    CRITICAL = 5,
    SECURITY = 6
};

void logMessage(string msg, int priority){
    string priority_str;
    ofstream file;
    file.open("log.txt", ios::app);
    if (!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    switch (priority){
        case DEBUG:
            priority_str = "[DEBUG]";
            break;
        case INFO:
            priority_str = "[INFO]";
            break;
        case WARNING:
            priority_str = "[WARNING]";
            break;
        case ERROR:
            priority_str = "[ERROR]";
            break;
        case CRITICAL:
            priority_str = "[CRITICAL]";
            break;
        case SECURITY:
            priority_str = "[SECURITY]";

            break;
        default: 
            priority_str = "[UNKNOWN]";
            break;
    }
    file << priority_str << " " << msg << endl;
    file.close();
}

void logMessage(string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream file;
    file.open("log.txt", ios::app);
    if (!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    file << "[ERROR] " << Mensage_de_Error << " en el archivo " << Archivo << " en la linea " << Línea_de_Código << endl;
    file.close();
}

bool check_user(string user){
    if (user == "admin"){
        return true;
    }
    return false;
}

void logMessage(string accecsMsg, string userName){
    ofstream file;
    file.open("log.txt", ios::app);
    if (!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    if (check_user(userName)){
        file << "[SECURITY] " << accecsMsg << " for " << userName << endl;
    }else{
        file << "[SECURITY] Acces Denied for " << userName << " (Access Denied)" << endl;
    }
    file.close();
}


int main(){
    string msg;
    int priority;
    cout << "Ingrese la prioridad (DEBUG(1), INFO(2), WARNING(3), ERROR(4), CRITICAL(5), SECURITY(6)): ";
    cin >> priority;
    if (priority == 4){
        string errorMsg, file;
        int line;
        cout << "Ingrese el mensaje de error: ";
        cin.ignore(); // Para limpiar el buffer (el "cin >> priority" deja un '\n' en el buffer)
        getline(cin, errorMsg);
        cout << "Ingrese el nombre del archivo: ";
        cin >> file;
        cout << "Ingrese la linea de codigo: ";
        cin >> line;
        logMessage(errorMsg, file, line);
        return 0;
    }
    if (priority == 6){
        string user;
        cout << "Ingrese el nombre de usuario: ";
        cin >> user;
        logMessage("Access Granted", user);
        return 0;
    }
    cout << "Ingrese el mensaje: ";
    cin.ignore(); // Para limpiar el buffer (el "cin >> priority" deja un '\n' en el buffer)
    getline(cin, msg);
    logMessage(msg, priority);
    return 0;
}