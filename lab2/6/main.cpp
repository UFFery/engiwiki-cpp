#include <stdio.h>
#include <math.h>

int main () {
    int a, summa;

    summa = 0;

    scanf("%d", &a);

    if (a == 0) {
        summa = 1;
    }

    while ( abs(a) > 0 ) {

        a = a / 10;
        summa = summa + 1;

    }

    printf("%d", summa);

}
