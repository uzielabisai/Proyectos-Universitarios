#include <iostream>
using namespace std; /* Utilizamos la directiva "using namespace std" para definir el espacio de nombres "std" */

int main()
{
	char continuar;
	int edad;
	
	do
	{
		cout<< "Por favor introduce tu edad para determinar si eres una persona mayor de edad o no." << endl;
		cin >> edad;
		
		if ( edad >= 18)
		{
			cout<< "¡Ya eres una persona mayor de edad!." << endl; /* Utilizamos un canal de salida estándar "cout" para mostrar mensaje en pantalla
			y "endl" para dar un salto de linea */
		}
		else 
		{
			cout<< "¡Aun no eres una persona mayor de edad!." << endl;
	    }
		do
        {
            cout << "Continuar (S/N): ";
            cin >> continuar;
            continuar = toupper(continuar); /* Convertir a mayúscula para que la comparación sea insensible a mayúsculas/minúsculas */
        } 
		while (continuar != 'S' && continuar != 'N'); /* Repetir hasta que se ingrese 'S' o 'N' */
	}
	while ( continuar == 'S' || continuar == 's');
	cout<< "Perfecto, que tengas suerte." << endl;
	
	return 0;
}