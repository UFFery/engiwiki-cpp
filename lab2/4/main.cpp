#include <stdio.h>
#include <math.h>

int main () {
    int a;

    scanf("%d", &a);

    int jopamin = a;
    int jopamax = a;
    
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
