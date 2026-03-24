#include<stdio.h>

int main() {
    int num, digit, rev = 0;
    int temp;
    printf("\nEnter the number:");
    scanf("%d", &num);
    temp = num;
    while(num != 0){
        digit = num%10;
        rev = rev*10 + digit;
        num/=10;
    }
    if(rev == temp)
    {
        printf("\n Entered number is %d", temp);
        printf("\n Reverse Number is %d", rev);
        printf("\n Hence Number is Palindrome");
    }
    else
    {
        printf("\n Entered number is %d", temp);
        printf("\n Reverse Number is %d", rev);
        printf("\n Hence Number is not Palindrome");
    }
    
}

// #include<stdio.h>

// void main() {
//     int digit_no, num, rev, rem;
//     printf("Enter the four digit number\n");
//     scanf("%d", &digit_no);
//     num = digit_no;
//     rev = 0;
//     printf("The given integer number = %d\n", num);
//     while(digit_no != 0)
//     {
//         rem = digit_no % 10;
//         rev = rev*10 + rem;
//         digit_no = digit_no/10;
//     }
//     printf("The reverse of given number = %d is %d\n", num, rev);
//     if(num == rev)
//         printf("The reverse number %d is palindrome\n", num);
//     else
//         printf("The given number %d is not a palindrome\n", num);
    
// }