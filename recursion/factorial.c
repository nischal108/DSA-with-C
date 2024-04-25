#include<stdio.h>

int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}


int main(){
    int n;
    printf("ENter the number you want to find the factorial of : ");
    scanf("%d",&n);

    printf("The factorial is : %d \n\n", factorial(n));


    return 0;
}