#include <stdio.h>
#include <stdlib.h>  
int main() {
    int m, n, i;
    
    printf("m-iin utgiin oruulna uu (0 ees yalgatai): ");
    scanf("%d", &m);
    
    printf("n-iin utgiig oruulna uu(0 ees yalgatai): ");
    scanf("%d", &n);
    
    if (m == 0 || n == 0) {
        printf("m bolon n ni 0 baij bolohgui\n");
        return 1;
    }

    int min;
    if (abs(m) < abs(n)) {
        min = abs(m);
    } else {
        min = abs(n);
    }
    printf("Eyreg bolon sorog buh yronhii huvaagchid:\n");
    for (i = 1; i <= min; i++) {
        if (m % i == 0 && n % i == 0) {
            printf("%d  %d\n", i, -i); 
        }
    }
    return 0;
}

