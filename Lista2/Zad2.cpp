#include <iostream>
#include <cstdlib>


int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;

    // Jeśli obie liczby są parzyste
    if (num1 % 2 == 0 && num2 % 2 == 0) {
        return num1 - num2; // Sortuj rosnąco
    }
    // Jeśli obie liczby są nieparzyste
    else if (num1 % 2 != 0 && num2 % 2 != 0) {
        return num2 - num1; // Sortuj malejąco
    }
    // W innym przypadku porządek wynika z parzystości
    else {
        return num1 % 2 == 0 ? -1 : 1; // Liczba parzysta przed liczbą nieparzystą
    }
}



int main() {
    int arr[] = {1, 4, 7, 2, 5, 9, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
