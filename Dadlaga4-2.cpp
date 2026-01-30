#include <iostream>
using namespace std;

int main() {
    double a[20];
    cout << "Massiviin elementuudiig oruulna uu:" << endl;
    for (int i = 0; i < 20; ++i) {
    	cout << "a[" << i << "] = ";
        cin >> a[i];
       
    }

    for (int i = 0; i < 10; ++i) {
        double first = a[i];
        double second = a[i + 10];

        if (first < second) {
            a[i] = second;      
            a[i + 10] = first;    
        }
        
    }

    cout << "\nHuvirgasnii daraah daraalal:" << endl;
    for (int i = 0; i < 20; ++i) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;
}

