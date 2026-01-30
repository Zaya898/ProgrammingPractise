#include <iostream>
using namespace std;

int main() {
    double x[10], y[10], sum = 0.0;

    cout << "x[i], y[i] iin utuudiig oruulna uu:" << endl;

    for (int i = 0; i < 10; ++i) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    for (int i = 0; i < 10; ++i) {
        double product = x[i] * y[i];
        cout << "x[" << i << "] * y[" << i << "] = " 
             << x[i] << " * " << y[i] << " = " << product << endl;
        sum += product;
    }

    cout << "\nNiit niilber= " << sum << endl;

    return 0;
}


