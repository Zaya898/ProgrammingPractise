#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void simplify_fraction(long long *numerator, long long *denominator) {
    if (*denominator == 0) return;
    
    long long common_divisor = gcd(llabs(*numerator), llabs(*denominator));
    *numerator /= common_divisor;
    *denominator /= common_divisor;
    
    if (*denominator < 0) {
        *numerator *= -1;
        *denominator *= -1;
    }
}
void combination(long long n, long long k, long long *num, long long *den) {
    if (k < 0 || k > n) {
        *num = 0;
        *den = 1;
        return;
    }
    
    *num = 1;
    *den = 1;
    if (k > n - k) k = n - k;
    for (long long i = 1; i <= k; i++) {
        *num *= (n - k + i);
        *den *= i;
        simplify_fraction(num, den);
    }
}
void sequence_a(int n, long long *v_num, long long *v_den) {
    v_num[0] = 1;
    v_den[0] = 1;
    
    for (int k = 1; k <= n; k++) {
        long long sum_num = v_num[0];
        long long sum_den = v_den[0];
        
        for (int i = 1; i <= k; i++) {
            long long c_num, c_den;
            combination(k+1, i, &c_num, &c_den);
            
            long long term_num = v_num[i-1] * c_num;
            long long term_den = v_den[i-1] * c_den;
            simplify_fraction(&term_num, &term_den);
            
            sum_num = sum_num * term_den + term_num * sum_den;
            sum_den *= term_den;
            simplify_fraction(&sum_num, &sum_den);
        }
        
        v_num[k] = -sum_num;
        v_den[k] = sum_den;
        v_den[k] *= (k+1);
        simplify_fraction(&v_num[k], &v_den[k]);
    }
}
void sequence_b(int n, long long *v_num, long long *v_den) {
    v_num[0] = 1;
    v_den[0] = 1;
    
    for (int k = 1; k <= n; k++) {
        long long sum_num = v_num[0];
        long long sum_den = v_den[0];
        
        for (int i = 1; i <= k; i++) {
            long long c_num, c_den;
            combination(2*k, 2*i, &c_num, &c_den);
            
            long long term_num = v_num[i-1] * c_num;
            long long term_den = v_den[i-1] * c_den;
            simplify_fraction(&term_num, &term_den);
            
            sum_num = sum_num * term_den + term_num * sum_den;
            sum_den *= term_den;
            simplify_fraction(&sum_num, &sum_den);
        }
        
        v_num[k] = -sum_num;
        v_den[k] = sum_den;
        simplify_fraction(&v_num[k], &v_den[k]);
    }
}

int main() {
    int max_n = 10;
    char choice;
    
    printf("Daraalaliin turuliin songono uu (a/b): ");
    scanf(" %c", &choice);
    
    printf("Heden gishuun tootsooloh ve?(n <= 10): ");
    int n;
    scanf("%d", &n);
    
    if (n > max_n) {
        printf("n Heterhii ih baina 10 aas ihgui utga oruulna uu.\n");
        return 1;
    }
    
    long long *v_num = (long long *)malloc((n+1) * sizeof(long long));
    long long *v_den = (long long *)malloc((n+1) * sizeof(long long));
    
    if (choice == 'a') {
        sequence_a(n, v_num, v_den);
    } else if (choice == 'b') {
        sequence_b(n, v_num, v_den);
    } else {
        printf("Buruu songolt!\n");
        free(v_num);
        free(v_den);
        return 1;
    }
    
    printf("Daraalaliin utguud:\n");
    for (int i = 0; i <= n; i++) {
        printf("v_%d = %lld/%lld", i, v_num[i], v_den[i]);
        if (v_den[i] == 1) printf(" = %lld", v_num[i]);
        printf("\n");
    }
    
    free(v_num);
    free(v_den);
    return 0;
}
