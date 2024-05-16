#include <iostream>
#include <vector>
#include <cstdlib>


int nimStrategy(std::vector<int>& piles) {
    int xorSum = 0;
    for (int pile : piles) {
        xorSum ^= pile;
    }


    if (xorSum == 0) {
        return -1;
    }


    int msb = 1;
    while (xorSum) {
        xorSum >>= 1;
        msb <<= 1;
    }

    msb >>= 1;


    for (int i = 0; i < piles.size(); ++i) {
        if (piles[i] & msb) {

            int stonesToRemove = piles[i] - (piles[i] ^ xorSum);
            return i;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "Program pomaga wygrać w grę Nim.\n"
                     "Sposób użycia:\n"
                     "nim liczba_1 liczba_2 ...\n"
                     "gdzie liczba_1,... to liczby kamieni w kolejnych rządach\n";
        return 0;
    }

    std::vector<int> piles;
    for (int i = 1; i < argc; ++i) {
        piles.push_back(std::atoi(argv[i]));
    }


    int optimalMove = nimStrategy(piles);
    if (optimalMove == -1) {
        std::cout << "Rób co chcesz, strategia wygrywająca nie istnieje\n";
    } else {
        std::cout << "Z rzędu nr " << (optimalMove + 1) << " zabierz " << piles[optimalMove] << " kamienie\n";
    }

    return 0;
}
