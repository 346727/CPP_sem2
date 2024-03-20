#include <iostream>
#include <cmath>


using namespace std;

double down(int n)
{
    double result = 0.0;
    for(int i=1; i<=n; i++)
    {
        result += 1.0/i;
    }

    return result;
}

double up(int n)
{
    double result = 0.0;
    for(int i=n; i>=1; i--)
    {
        result += 1.0/i;
    }

    return result;
}


//FLOATY
float downF(int n)
{
    float result = 0.0;
    for(int i=1; i<=n; i++)
    {
        result += 1.0/i;
    }

    return result;
}

float upF(int n)
{
    float result = 0.0;
    for(int i=n; i>=1; i--)
    {
        result += 1.0/i;
    }

    return result;
}

int main()
{
    cout << "****************PODPUNKT A****************" << endl;

    cout << "Roznica n=100: " << up(100) - down(100) << endl;
    cout << "Roznica n=100: " << up(100000) - down(100000) << endl;
    cout << "Roznica n=100: " << up(100000000) - down(100000000) << endl;

    cout << "****************PODPUNKT B****************" << endl;

    cout << "Roznica n=100: " << downF(100) - upF(100) << endl;
    cout << "Roznica n=100: " << upF(100000) - downF(100000) << endl;
    cout << "Roznica n=100: " << upF(100000000) - downF(100000000) << endl;

    return 0;

}