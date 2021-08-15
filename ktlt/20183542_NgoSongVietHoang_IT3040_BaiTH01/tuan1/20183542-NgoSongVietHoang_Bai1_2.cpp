#include <stdio.h>

int main() {

    int x, y, z;

    int *ptr;
    printf("Ho Va Ten: Ngo Song Viet Hoang\n");
    printf("MSSV: 20183542\n\n");

    scanf("%d %d %d", &x, &y, &z);

    printf("Here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);



    /*****************

    # YOUR CODE HERE #

    *****************/
    x += 100;
    y += 100;
    z += 100;


    printf("Once again, here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);

    return 0;

}
