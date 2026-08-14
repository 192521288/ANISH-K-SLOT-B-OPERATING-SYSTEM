#include <stdio.h>

int main() {
    int n, start, i;

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("\nFile No.\tAllocated Block\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i + 1, start + i);
    }

    return 0;
}