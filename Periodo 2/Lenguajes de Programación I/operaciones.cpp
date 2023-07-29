#include <iostream>
using namespace std;

int main()
{
    long double n1, n2;
    char continuar;
    do
    {
        cout << "Por favor, ingresa dos valores para realizar las operaciones correspondientes:" << endl;
        cout << "Escribe el primer número:" << endl;
        cin >> n1;
        cout << "Escribe el segundo número:" << endl;
        cin >> n2;
        cout << "La suma es: " << n1 + n2 << endl;
        cout << "La resta es: " << n1 - n2 << endl;
        cout << "La multiplicación es: " << n1 * n2 << endl;
        cout << "La división es: " << n1 / n2 << endl;

        do
        {
            cout << "¿Deseas continuar con otras operaciones? (S/N):" << endl;
            cin >> continuar;
            continuar = toupper(continuar);
        } while (continuar != 'S' && continuar != 'N');
    } while (continuar == 'S' || continuar == 's');
    cout << "¡Perfecto, nos vemos pronto!" << endl;
    return 0;
}
