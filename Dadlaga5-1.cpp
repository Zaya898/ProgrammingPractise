#include <stdio.h>
#include <stdbool.h>

void findUniqueElements(int arr[], int n) {
    printf("a)  Gants udaa orson toonuud: ");
    for (int i = 0; i < n; i++) {
        bool unique = true;
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                unique = false;
                break;
            }
        }
        if (unique) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void findAllDistinctElements(int arr[], int n) {
    printf("b)  Yadaj neg udaa orson buh toonuud: ");
    for (int i = 0; i < n; i++) {
        bool printed = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                printed = true;
                break;
            }
        }
        if (!printed) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void countDistinctElements(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isNew = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isNew = false;
                break;
            }
        }
        if (isNew) {
            count++;
        }
    }
    printf("c)  Yalgaatai gishuudiin too: %d\n", count);
}

void countExactlyOnceElements(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool exactlyOnce = true;
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                exactlyOnce = false;
                break;
            }
        }
        if (exactlyOnce) {
            count++;
        }
    }
    printf("d) Yg neg udaa orson gishuudiin too: %d\n", count);
}

void countRepeatedElements(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool repeated = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                repeated = true;
                break;
            }
        }
        if (!repeated) {
            int occurrences = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    occurrences++;
                }
            }
            if (occurrences > 1) {
                count++;
            }
        }
    }
    printf("e) Negees olon udaa orson gishuudiin too: %d\n", count);
}

bool hasRepeatedPairs(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    printf("Daraalaliin urtiig oruulna uu: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Daraalliin toonuudiig oruulna uu: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    findUniqueElements(arr, n);
    findAllDistinctElements(arr, n);
    countDistinctElements(arr, n);
    countExactlyOnceElements(arr, n);
    countRepeatedElements(arr, n);
    
    bool hasRepeats = hasRepeatedPairs(arr, n);
    printf("f) Daraalald davtagdan orson hos too baigaa eseh: %s\n", hasRepeats ? "????" : "????");
    
    return 0;
}
