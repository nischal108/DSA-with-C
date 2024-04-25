#include <stdio.h>

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sum(n - 1);
    }
}

int main()
{
    int result = sum(100);
    printf("Sum from 1 to 100: %d\n", result);
    return 0;
}
