#include <iostream>
#include <cmath>


using namespace std;

//podpunkt A
int sumaA(const int tab[], unsigned size){
    int sum = 0;
    for(unsigned i = 0; i < size; i++){ 
        sum += tab[i];
    }

    return sum;
}

//Podpunkt B
void sumaB(const int tab[], unsigned size, int* result){
    int sum = 0;
    for(unsigned i = 0; i < size; i++){ 
        sum += tab[i];
    }

    *result = sum;
}

void reverse(int* tab, size_t size){
    for(size_t i=0; i<size/2; i++)
    {
        swap(tab[i], tab[size-i-1]);
    }
}

void pisz(const int* tab, size_t size, std::ostream *out) {
    for (size_t i = 0; i < size; ++i) {
        *out << tab[i] << " ";
    }
}

void iota(int tab[], unsigned size) {
    for (unsigned i = 0; i < size; ++i) {
        tab[i] = i;
    }

}

int dot_product(const int* tab1, const int* tab2, size_t size) {
    int result = 0;
    for (size_t i = 0; i < size; ++i) {
        result += tab1[i] * tab2[i];
    }
    return result;
}


int main()
{
    int tablica1[] = {1, 2, 3};
    int wynik;

    cout << "****************PODPUNKT A****************" << endl;
    cout << sumaA(tablica1, 2) << endl;
    sumaB(tablica1, 2, &wynik);
    //cout << endl;

    cout << "****************PODPUNKT B****************" << endl;
    cout << wynik << endl;
    pisz(tablica1, 2, &cout);
    cout << endl;

    cout << "****************PODPUNKT C****************" << endl;
    int tablica[] = {1, 2, 3, 4, 5};
    pisz(tablica, 3, &std::cout);
    cout << endl;
    
    cout << "****************PODPUNKT D****************" << endl;
    int tabb[3];
    iota(tabb, 3);
    for (unsigned i = 0; i < 3; ++i) {
        cout << tabb[i] << " ";
    }
        cout << endl;

    cout << "****************PODPUNKT E****************" << endl;
    int tabc[3] = {1, 2, 3};
    reverse(tabc, 3);
    for (unsigned i = 0; i < 3; ++i) {
        cout << tabc[i] << " ";
    }

    cout << endl;


    cout << "****************PODPUNKT F****************" << endl;
    int tabA[3] = {1, 2, 3};
    int tabB[3] = {4, 5, 6};
    cout << dot_product(tabA, tabB, 3) << endl;

    return 0;
}
