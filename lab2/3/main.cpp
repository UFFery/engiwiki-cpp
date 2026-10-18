#include <stdio.h>

int main () {
    int a;
    int jopamin = 0;
    int jopamax = 0;

    scanf("%d", &a);

    if(jopamin == 0) {
            jopamin = a;
        }

    if(jopamax == 0) {
        jopamax = a;
    }

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
