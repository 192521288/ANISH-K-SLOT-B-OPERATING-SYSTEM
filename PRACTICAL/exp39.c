#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], temp;
    int n, head, size;
    int i, j, total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request queue:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total number of tracks: ");
    scanf("%d", &size);

    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Find first request greater than or equal to head
    for (i = 0; i < n; i++) {
        if (req[i] >= head)
            break;
    }

    printf("\nSeek Sequence: %d", head);

    // Move towards higher tracks
    for (j = i; j < n; j++) {
        total += abs(req[j] - head);
        head = req[j];
        printf(" -> %d", head);
    }

    // Move to last track
    total += abs((size - 1) - head);
    head = size - 1;
    printf(" -> %d", head);

    // Jump to first track
    total += size - 1;
    head = 0;
    printf(" -> %d", head);

    // Continue servicing remaining requests
    for (j = 0; j < i; j++) {
        total += abs(req[j] - head);
        head = req[j];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", total);
    printf("\nAverage Seek Time = %.2f\n", (float)total / n);

    return 0;
}