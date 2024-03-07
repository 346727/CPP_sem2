#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 1000000;
    //podpunkt a:
    double suma = 0.0;

    for(int j=1; j <= n; j++)
    {
        suma += 4.0 * pow(-1.0, j+1) / (2.0 * j - 1);
    }

    cout << "Podpunkt a: " << suma << endl;

    //podpunkt b:
    double iloczyn = 1.0;
    for (int j = 1; j <= n; j++)
    {
            iloczyn *= (4.0 * j * j) / (4.0 * j * j - 1.0);
    }

    cout << "Podpunkt b: " << 2.0 * iloczyn << endl;

    //Podpunkt c:
    double sumaC = 0.0;
    for (int j = 1; j <= n; j++)
    {
        sumaC +=  8*(1 / pow(2.0 * j - 1, 2));
    }

    sumaC = sqrt(sumaC);

    cout << "Podpunkt c: " << sumaC << endl;

    cout << "Liczba pi: " << 3.14159265358979323846 << endl;



    return 0;
}
    

