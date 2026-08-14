#include <stdio.h>

int main() {
    int pages[50], frame[10];
    int n, f, i, j, k;
    int faults = 0, found, pos, farthest;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in frame
        for (j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page Fault
        if (!found) {
            faults++;

            // Fill empty frame first
            for (j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    found = 1;
                    break;
                }
            }

            // Replace optimally
            if (!found) {
                farthest = -1;
                pos = -1;

                for (j = 0; j < f; j++) {
                    int next = n;

                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            next = k;
                            break;
                        }
                    }

                    if (next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }

                frame[pos] = pages[i];
            }
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++) {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}