#include <stdio.h>

int main () {
    int a;

    scanf("%d", &a);

    int jopamin = a;
    int jopamax = a;

    while (a != 0){

        if (a > jopamax) {
            jopamax = a;
        }

        if (a < jopamin) {
            jopamin = a;
        }

        scanf("%d", &a);
    }

    printf("%d %d", jopamax, jopamin );

}
