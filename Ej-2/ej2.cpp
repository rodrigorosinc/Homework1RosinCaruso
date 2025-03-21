#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Priority{ //enum para los niveles de prioridad
    DEBUG = 1,
    INFO = 2,
    WARNING = 3,
    ERROR = 4,
    CRITICAL = 5,
    SECURITY = 6,
    OTHER = 7
};

void logMessage(string msg, int priority){ //funcion para loggear mensajes
    string priority_str; 
    ofstream file;
    file.open("log.txt", ios::app); 
    if (!file.is_open()){
        cout << "Error while opening file" << endl; //si no se pudo abrir el archivo, imprimir mensaje de error
        return;
    }
    switch (priority){ //switch para asignar la prioridad
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
        case OTHER:
            priority_str = "[OTHER]";
            break;
    }
    file << priority_str << " " << msg << endl; //escribir en el archivo
    file.close(); //cerrar el archivo
}

void logMessage(string errorMsg, string givenFile, int line){ //funcion para loggear errores de forma mas especifica
    ofstream file;
    file.open("log.txt", ios::app); 
    if (!file.is_open()){
        cout << "Error while opening file" << endl;
        return;
    }
    file << "[ERROR] " << errorMsg << " in file " << givenFile << " in line " << line << endl; //escribir en el archivo
    file.close();
}

bool check_user(string user){ //funcion para verificar el user para el log de seguridad
    if (user == "admin"){
        return true;
    }
    return false;
}

void logMessage(string accesMsg, string userName){ //funcion para loggear mensajes de seguridad
    ofstream file;
    file.open("log.txt", ios::app);
    if (!file.is_open()){
        cout << "Error while opening file" << endl;
        return;
    }
    if (check_user(userName)){ //verificar el user
        file << "[SECURITY] " << accesMsg << " for " << userName << endl; //si el acceso esta permitido lo escribe en el archivo
    }else{
        file << "[SECURITY] Acces Denied for " << userName << endl;       //si no, escribe que el acceso fue denegado
    }
    file.close();
}

int main(){ // Ejemplo de uso:
    try {
    // Pregunto si quiero cargar los ejemplos hardcodeados
    bool showExamples; 
    cout << "Load hardcoded examples? (1 for yes, 0 for no): ";
    cin >> showExamples;
    cin.ignore(); //para limpiar el buffer (el "cin >> showExamples" deja un '\n' en el buffer)
    if (showExamples){
    logMessage("This is a debug message", DEBUG);       //logueo de mensaje de debug con logMessage
    logMessage("This is an info message", INFO);        //logueo de mensaje de info con logMessage
    logMessage("This is a warning message", WARNING);   //logueo de mensaje de warning con logMessage
    logMessage("This is an error message", ERROR);      //logueo de error con logMessage
    logMessage("Runtime error", __FILE__, __LINE__);    //logueo de error con el logMessage especifico para errores
    logMessage("This is a critical message", CRITICAL); //logueo de mensaje critico con logMessage
    logMessage("This is a security message", SECURITY); //logueo de mensaje de seguridad con logMessage
    logMessage("Acces granted", "admin");               //logueo de mensaje de seguridad con logMessage especifico para seguridad
    logMessage("This is an other message", OTHER);      //logueo de mensaje de otro tipo con logMessage
    }

    string msg; int priority;
    // Pido la prioridad
    cout << "Input priority (DEBUG(1), INFO(2), WARNING(3), ERROR(4), CRITICAL(5), SECURITY(6), OTHER(7)): "; 
    cin >> priority;
    if (priority == 4){ //si la prioridad es 4, pido el mensaje de error, el archivo y la linea
        string errorMsg, file;
        int line;
        cout << "Input error msg: ";
        cin.ignore();   //limpiar el buffer
        getline(cin, errorMsg);
        cout << "Input file: ";
        cin >> file;
        cout << "Input line: ";
        cin >> line;
        logMessage(errorMsg, file, line);
    } else if (priority == 6){ //si la prioridad es 6, pido el mensaje de acceso y el user
        string user;
        cout << "Input user name: ";
        cin >> user;
        cin.ignore();         //limpiar el buffer
        logMessage("Access Granted", user);
    } else if (priority > 8){ //si la prioridad es mayor a 8, tiro un error
        throw runtime_error("Invalid priority");
        return 1;
    } else {          //si no, pido el mensaje
        cout << "Input msg: ";
        cin.ignore(); //limpiar el buffer
        getline(cin, msg);
        logMessage(msg, priority);
    }

    // Pregunto si quiero tirar un error
    bool throwErr;
    cin.ignore(); //limpiar el buffer
    cout << "Throw error? (1 for yes, 0 for no): ";
    cin >> throwErr;
    if (throwErr){
        throw runtime_error("Error thrown");
        return 1;
    }
    
    } catch (runtime_error &e){ //catch para los errores de donde sea que se tiren
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }
    return 0;
}   