#include <stdio.h>
#include <math.h>
long long fibonacci_recursive(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return fibonacci_recursive(k-1) + fibonacci_recursive(k-2);
}
long long fibonacci_binet(int k) {
    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5) / 2;  
    double fib = (pow(phi, k) / sqrt5);
    return (long long)round(fib);
}

int main() {
    const int max_k = 15;
    const double sqrt5 = sqrt(5);
    const double phi = (1 + sqrt5) / 2; 
    
    printf("k\tRecursiv\tBinegin\tOiroltsoo utga\tYalgaa\n");
    printf("------------------------------------------------------------\n");
    
    for (int k = 0; k <= max_k; k++) {
        long long fib_rec = fibonacci_recursive(k);
        long long fib_binet = fibonacci_binet(k);
        double approx = pow(phi, k) / sqrt5;
        
        printf("%d\t%lld\t\t%lld\t\t%.2f\t\t%lld\n", 
               k, fib_rec, fib_binet, approx, fib_rec - fib_binet);
    }
    
    return 0;
}
