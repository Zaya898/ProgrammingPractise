#include <iostream>
using namespace std;
struct Node {
    double value;
    Node* next;
};
int main() {
    int n;
    cout << "n (n <= 1000) oruul: ";
    cin >> n;

    if (n < 2 || n > 1000) {
        cout << "Aldaa: n ni 2-1000 hoorond baih ystoi.\n";
        return 1;
    }

    Node* head = NULL;
    Node* tail = NULL;

    cout << n << " shirheg bodit too oruul:\n";
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        Node* temp = new Node;
        temp->value = x;
        temp->next = NULL;

        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    double lastValue = current->value;
    cout << "\nGaralt:\n";
    current = head;
    for (int i = 0; i < n - 1; ++i) {
        cout << current->value - lastValue << endl;
        current = current->next;
    }
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

