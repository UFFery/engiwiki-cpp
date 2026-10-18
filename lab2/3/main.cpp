#include <stdio.h>

int main () {
    int a;
    int jopamin = 0;
    int jopamax = 0;
    do {
        scanf("%d", &a);

        if (a > jopamax) {
             jopamax = a;
        }

        if (a < jopamin) {
            jopamin = a;
        }
        

    } while (a != 0);

    printf("%d %d", jopamax, jopamin );

}
