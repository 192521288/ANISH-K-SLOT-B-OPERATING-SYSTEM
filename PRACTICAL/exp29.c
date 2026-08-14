#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;

void producer() {
    if ((mutex == 1) && (empty != 0)) {
        mutex = 0;
        x++;
        printf("Producer produces item %d\n", x);
        full++;
        empty--;
        mutex = 1;
    } else {
        printf("Buffer is Full!\n");
    }
}

void consumer() {
    if ((mutex == 1) && (full != 0)) {
        mutex = 0;
        printf("Consumer consumes item %d\n", x);
        x--;
        full--;
        empty++;
        mutex = 1;
    } else {
        printf("Buffer is Empty!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Producer");
        printf("\n2. Consumer");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;

            case 2:
                consumer();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }

        printf("Buffer Status: Full = %d, Empty = %d\n", full, empty);
    }

    return 0;
}