#include <stdio.h>

int main() {
    int n, indexBlock, blocks[20], i;

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter the block numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndexed File Allocation\n");
    printf("Index Block: %d\n\n", indexBlock);

    printf("Entry\tData Block\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i + 1, blocks[i]);
    }

    return 0;
}