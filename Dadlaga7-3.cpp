#include <iostream>
#include <set>
using namespace std;

int main() {
    int k, m, n;
    cout << "k, m, n-iin utgiig oruulna uu:(k + m + n<=2000): ";
    cin >> k >> m >> n;

    if (k + m + n > 2000) {
        cout << "Aldaa: k + m + n ni 2000-aas ih bna!\n";
        return 1;
    }

    string s, t, u;
    char ch;
    cout << "s1...sk daraalliin " << k << " temdegtuudiig oruul:\n";
    for (int i = 0; i < k; ++i) {
        cin >> ch;
        s += ch;
    }

    cout << "t1...tm daraalliin " << m << " temdegtiin oruul:\n";
    for (int i = 0; i < m; ++i) {
        cin >> ch;
        t += ch;
    }

    cout << "u1...un daraalliin " << n << " temdegtiin oruul:\n";
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        u += ch;
    }
    set<char> set1(s.begin(), s.end());
    set<char> set2(t.begin(), t.end());
    set<char> set3(u.begin(), u.end());
    set<char> result;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (set1.count(ch) && set2.count(ch) && set3.count(ch)) {
            result.insert(ch);
        }
    }

    cout << "\nGurvuuland ni orson temdetuud:\n";
    for (set<char>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}

