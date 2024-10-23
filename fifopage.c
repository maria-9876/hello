#include <stdio.h>
#include <stdlib.h>

void printframe(int frames[], int frameno) {
    for (int i = 0; i < frameno; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int frameno, pageno, i, j;
    int pages[20];

    printf("Enter the number of frames: ");
    scanf("%d", &frameno);

    printf("Enter the number of pages: ");
    scanf("%d", &pageno);

    printf("Enter the page reference string: ");
    for (i = 0; i < pageno; i++) {
        scanf("%d", &pages[i]);
    }

    int frames[20];
    int index = 0;
    int pagefaults = 0;

    for (i = 0; i < frameno; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < pageno; i++) {
        int found = 0;
        for (j = 0; j < frameno; j++) {  // Correct loop increment
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            frames[index] = pages[i];
            index = (index + 1) % frameno;
            pagefaults++;
        }

        printframe(frames, frameno);
    }

    printf("Number of Page Faults: %d\n", pagefaults);
    return 0;
}
