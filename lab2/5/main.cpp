#include <stdio.h>

int main () {
    int a;
    int sumo = 0;
    int cacaunt = 0;

    scanf("%d", &a);

    while (a != 0){

        sumo = sumo + a;
        cacaunt = cacaunt + 1;

        scanf("%d", &a);
    }
    
    double avg = (double)sumo / cacaunt;

    printf("%lf", avg);

}
