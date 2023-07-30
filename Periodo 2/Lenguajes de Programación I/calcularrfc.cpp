#include <iostream>
#include <string>
using namespace std;

class RFCGenerator {
public:
    string generateRFC(string nombre, string apellidoPaterno, string apellidoMaterno, string fechaNacimiento) {
        string rfc = "";

        // Primeros 2 caracteres (VE)
        rfc += obtenerPrimerCaracter(apellidoPaterno) + obtenerVocalInterna(apellidoPaterno);

        // 3ra posición: Inicial del apellido materno (o 'X' si no existe)
        rfc += (apellidoMaterno.empty()) ? 'X' : obtenerPrimerCaracter(apellidoMaterno);

        // 4ta posición: Inicial del primer nombre (o 'X' si no existe)
        rfc += (nombre.empty()) ? 'X' : obtenerPrimerCaracter(nombre);

        // 5ta y 6ta posición: Dos últimos dígitos del año de nacimiento
        rfc += fechaNacimiento.substr(8, 2);

        // 7ma y 8va posición: Mes de nacimiento
        rfc += fechaNacimiento.substr(3, 2);

        // 9na y 10ma posición: Día de nacimiento
        rfc += fechaNacimiento.substr(0, 2);

        // Homoclave: Utilizamos XXX
        rfc += "XXX";

        return rfc;
    }

private:
    char obtenerPrimerCaracter(string str) {
        return toupper(str[0]);
    }

    char obtenerVocalInterna(string str) {
        for (size_t i = 1; i < str.length(); ++i) {
            if (esVocal(str[i])) {
                return toupper(str[i]);
            }
        }
        return 'X'; // Si no se encuentra ninguna vocal interna
    }

    bool esVocal(char c) {
        c = toupper(c);
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};

int main() {
    string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;

    cout << "Ingrese el nombre: ";
    getline(cin, nombre);

    cout << "Ingrese el apellido paterno: ";
    getline(cin, apellidoPaterno);

    cout << "Ingrese el apellido materno (deje en blanco si no tiene): ";
    getline(cin, apellidoMaterno);

    cout << "Ingrese la fecha de nacimiento (formato dd/mm/aaaa): ";
    getline(cin, fechaNacimiento);

    RFCGenerator rfcGenerator;
    string rfc = rfcGenerator.generateRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);

    cout << "El RFC calculado es: " << rfc << endl;

    return 0;
}


