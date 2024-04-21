#include <stdio.h>

void moveDisk(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    moveDisk(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moveDisk(n - 1, auxiliary, destination, source);
}

int main()
{
    int numDisks;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Move disks from 'A' to 'C' using 'B' as auxiliary
    moveDisk(numDisks, 'A', 'C', 'B');

    return 0;
}
