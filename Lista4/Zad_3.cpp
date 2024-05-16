#include <iostream>
#include <cstring>
#include <cstdlib> 

int main(int argc, char* argv[])
{
    if (argc > 1) 
    {
        if (argc % 2 == 0) 
        {
            bool poprawneDane = true;
            int stosy[argc - 1];
            int najwiekszy = 0;
            int indeksNajwiekszego = -1;
            
            for (int i = 1; i < argc; i++)
            {
                bool poprawne = true;
                for (int j = 0; j < std::strlen(argv[i]); j++)
                {
                    if (!std::isdigit(argv[i][j]))
                    {
                        poprawne = false;
                        break;
                    }
                }
                
                if (poprawne)
                {
                    stosy[i - 1] = atoi(argv[i]);
                    if (stosy[i - 1] > najwiekszy)
                    {
                        najwiekszy = stosy[i - 1];
                        indeksNajwiekszego = i - 1;
                    }
                }
                else
                {
                    std::cout << "Nieprawidłowe dane. Prosze podaj tylko liczby całkowite." << std::endl;
                    poprawneDane = false;
                    break;
                }
            }
            
            if (poprawneDane)
            {
                if (najwiekszy > 0)
                    std::cout << "Zabierz " << najwiekszy << " kamieni ze stosu " << indeksNajwiekszego + 1 << "." << std::endl;
                else
                    std::cout << "Błąd! Upewnij się, że dane wejściowe są poprawne." << std::endl;
            }
        }
        else
        {
            std::cout << "mozesz robic co tylko chcesz; nie ma żadnej strategii wygrywającej." << std::endl;
        }
    }
    else
    {
        std::cout << "Program do określania najlepszego ruchu w grze Nim - podaj liczby kamieni w każdym stosie jako argumenty programu." << std::endl;
    }
    
    return 0;
}