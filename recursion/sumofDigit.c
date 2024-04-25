#include <stdio.h>

int sumofDigit(int n)
{
    if (n < 10)
        return n;
    else
    {
        return (n%10 + sumofDigit(n / 10));
    }
}

int main()
{
    int n;
    printf("Enter the digit : ");
    scanf("%d", &n);

    printf("%d  \n\n", sumofDigit(n));

        return 0;
}
