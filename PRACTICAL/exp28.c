#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], word[50], line[500];
    int lineNo = 1, found = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    printf("\nMatching Lines:\n");

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word) != NULL) {
            printf("Line %d: %s", lineNo, line);
            found = 1;
        }
        lineNo++;
    }

    if (!found)
        printf("Word not found in the file.\n");

    fclose(fp);
    return 0;
}