#include <stdio.h>
#include <math.h>

int find_maximum_pythagorean_triplet(int n) {
    if (n % 2 != 0)
        return -1;
    int m = -1;
    for (int a = 1; a <= (n/3); a++) {
        int b = (n*(n - 2*a))/(2*(n - a));
        int c = n - a - b;
        if (a * a + b * b == c * c)
            if (a * b * c > m)
                m = a * b * c;
    }
    return m;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int a0 = 0; a0 < t; a0++) {
        int n;
        scanf("%d", &n);
        int result = find_maximum_pythagorean_triplet(n);
        printf("%d\n", result);
    }
    return 0;
}