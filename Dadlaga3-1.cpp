#include <stdio.h>
int main() {
    int n, i;
    printf("n-iin utgiin oruulna uu (n >= 3): ");
    scanf("%d", &n);

    if (n < 3) {
        printf("n ni 3 aas baga baij bolohguu\n");
        return 1;
    }

    double a[n];       
    double b[n - 2];   
    printf("a massiviin %d shirhel element oruulna uu:\n", n);
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    for (i = 0; i < n - 2; i++) {
        b[i] = a[i + 1] + a[i + 2];
    }

    printf("\n%s%14s\n", "Index", "a[i]");
    for (i = 0; i < n; i++) {
        printf("%3d %15.2lf\n", i, a[i]);
    }

    printf("\n%s%25s\n", "Index", "b[i] = a[i+1] + a[i+2]");
    for (i = 0; i < n - 2; i++) {
        printf("%3d %20.2lf\n", i, b[i]);
    }

    return 0;
}

