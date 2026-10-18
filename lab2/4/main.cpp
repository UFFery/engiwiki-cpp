#include <stdio.h>
#include <math.h>

int main () {
    int a;
    int jopamin = 0;
    int jopamax = 0;

    scanf("%d", &a);

    if(jopamin == 0) {
            jopamin = a;
        }

    while (a != 0){

        if (abs(a) > abs(jopamax)) {
            jopamax = a;
        }

        if (abs(a) < abs(jopamin)) {
            jopamin = a;
        }

        scanf("%d", &a);
    }

    printf("%d %d", jopamax, jopamin );

}
