// Bài tập 1
// Viết một chương trình C nhập vào 3 số nguyên. Thiết lập một con trỏ để lần lượt trỏ tới từng số nguyên và hiển thị kết quả giá trị tham chiếu ngược của con trỏ.
// Lưu ý: Phép toán & trả về địa chỉ của biến.

# include <stdio.h>
int main(){
    int x, y, z;
    int* ptr;
    int* ptr1;
    int* ptr2;
    printf("Ho Va Ten: Ngo Song Viet Hoang\n");
    printf("MSSV: 20183542\n\n");
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nThe three integers are:\n");
    ptr = &x;
    ptr1 = &y;
    ptr2 = &z;
    printf("x = %d\n", *ptr);
    printf("y = %d\n", *ptr1);
    printf("z = %d\n", *ptr2);


    /*****************
    # YOUR CODE HERE #
    *****************/

    return 0;
}
