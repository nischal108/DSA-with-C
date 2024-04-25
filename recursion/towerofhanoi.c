#include <stdio.h>

void moveDisk(int n, char source, char destination, char temp)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    moveDisk(n - 1, source, temp, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moveDisk(n - 1, temp, destination, source);
}

int main()
{
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);


    moveDisk(numDisks, 'A', 'C', 'B');

    return 0;
}
