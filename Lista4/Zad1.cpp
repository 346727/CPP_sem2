#include <iostream>
#include <vector>
using namespace std;

double operator*(const vector<double> &v, const vector<double> &w) {
    double scalarProduct = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        scalarProduct += v[i] * w[i];
    }
    return scalarProduct;
}

int main() {
    vector<double> v;
    v.push_back(1.0);
    v.push_back(2.0);
    v.push_back(3.0);

    vector<double> w;
    w.push_back(4.0);
    w.push_back(5.0);
    w.push_back(6.0);

    double dotProduct = v * w;

    cout << "Iloczyn skalarny v i w: " << dotProduct << endl;

    return 0;
}
