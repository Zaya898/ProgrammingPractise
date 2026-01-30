#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef struct {
    int x, y;
} Point;

bool isSame(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

bool pointExists(Point points[], int n, Point p) {
    for (int i = 0; i < n; i++) {
        if (isSame(points[i], p))
            return true;
    }
    return false;
}

void findSquare(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            Point A = points[i];
            Point C = points[j];
            int dx = C.x - A.x;
            int dy = C.y - A.y;
            Point B1 = { A.x + dy, A.y - dx };
            Point D1 = { C.x + dy, C.y - dx };
            Point B2 = { A.x - dy, A.y + dx };
            Point D2 = { C.x - dy, C.y + dx };

            if (pointExists(points, n, B1) && pointExists(points, n, D1)) {
                printf("Kvadrat uusgeh tseguud:\n");
                printf("A: (%d, %d)\n", A.x, A.y);
                printf("B: (%d, %d)\n", B1.x, B1.y);
                printf("C: (%d, %d)\n", C.x, C.y);
                printf("D: (%d, %d)\n", D1.x, D1.y);
                return;
            }

            if (pointExists(points, n, B2) && pointExists(points, n, D2)) {
                printf("Kvadrat uusgeh tseguud:\n");
                printf("A: (%d, %d)\n", A.x, A.y);
                printf("B: (%d, %d)\n", B2.x, B2.y);
                printf("C: (%d, %d)\n", C.x, C.y);
                printf("D: (%d, %d)\n", D2.x, D2.y);
                return;
            }
        }
    }

    printf("Kvadrat uusgeh dorvon tseg oldsongui\n");
}

int main() {
    int n;
    Point points[MAX];

    printf("Tsegiin too oruul (<= 1000): ");
    scanf("%d", &n);

    if (n > MAX || n < 4) {
        printf("Buruu too oruulsan!\n");
        return 1;
    }

    printf("%d tsegiin kordinat oruul:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    findSquare(points, n);

    return 0;
}
 
