# include <stdio.h>

double* maximum(double* a, int size){

    double *max;

    max = a;
    if (a==NULL) return NULL;



    // /*****************

    // # YOUR CODE HERE #

    // *****************/
    printf("Ho Va Ten: Ngo Song Viet Hoang\n");
    printf("MSSV: 20183542\n\n");
    for (int i = 0;i<size; i++){
        if (a[i] > *max){
            *max = a[i];
        }
    }


    return max;

}
int main(){
    double arr[] = {23, 10., 2., -7., 25., 3.};
    double* max = maximum(arr, 6);
    printf("%.0f", *max);
}
