#include <stdio.h>

void printFrames(int frames[], int frameno) {
    for (int i = 0; i < frameno; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

int main() {
    int frameno, pageno, i, j, k;
    int pages[20], frames[20];

    printf("Enter the number of frames: ");
    scanf("%d", &frameno);

    printf("Enter the number of pages: ");
    scanf("%d", &pageno);

    printf("Enter the page reference string: ");
    for (i = 0; i < pageno; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < frameno; i++) {
        frames[i] = -1;
    }

    int pagefaults = 0;
    int used[20] = {0};

    printf("The page replacement process is:\n");

    for (i = 0; i < pageno; i++) {
        int found = 0;
        for (j = 0; j < frameno; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                used[j] = i + 1;
                break;
            }
        }

        if (found == 0) {
            int min_time = used[0], min_index = 0;
            for (j = 1; j < frameno; j++) {
                if (used[j] < min_time) {
                    min_time = used[j];
                    min_index = j;
                }
            }
            frames[min_index] = pages[i];
            used[min_index] = i + 1;
            pagefaults++;
        }

        printFrames(frames, frameno);
    }

    printf("The total number of page faults using LRU are: %d\n", pagefaults);

    return 0;
}
