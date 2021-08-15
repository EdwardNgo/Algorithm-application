#include <stdio.h>
int main(){
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
    printf("Ho Va Ten: Ngo Song Viet Hoang\n");
    printf("MSSV: 20183542\n\n");
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++)  printf("\ta[%d] ",i);
    printf("\n");
    for (int i=0; i<5;i++)  printf("\t%d ",&a[i]);

    /*****************
    # YOUR CODE HERE #
    *****************/

    return 0;
}
