#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, i;
    int total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request queue:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for (i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", total);
    printf("\nAverage Seek Time = %.2f\n", (float)total / n);

    return 0;
}