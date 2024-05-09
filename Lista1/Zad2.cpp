#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Podpunkt a:
    cout << "------------------Podpunkt a------------- " << endl;
    double sumaA[31] = {1/sqrt(3)};
    for(int i=1; i<=30; i++)
    {
        sumaA[i] = (sqrt(sumaA[i-1]*sumaA[i-1] - 1) - 1)/sumaA[i-1];
        double pi = 6 * pow(2.0, i) * sumaA[i-1];
        cout << pi << endl;
    }

    cout << "-----------------------------------------------------" << endl;

    //Podpunkt b:
    cout << "------------------Podpunkt b------------- " << endl;
    double sumaB[31] = {1/sqrt(3)};
    for(int i=1; i<=30; i++)
    {
        sumaB[i] = sumaB[i-1]/(sqrt(sumaB[i-1]*sumaB[i-1] + 1) + 1);
        double pi = 6 * pow(2.0, i) * sumaB[i-1];
        cout << pi << endl;

    }

    return 0;
}
