#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter the number of files to be allocated\n");
    scanf("%d", &n);
    
    char fileNames[n][20];
    int startBlocks[n];
    int lengths[n];
    
    for(i = 0; i < n; i++) {
        printf("Enter the name of the file %d\n", i + 1);
        scanf("%s", fileNames[i]);
        printf("Enter the start block of the file %d\n", i + 1);
        scanf("%d", &startBlocks[i]);
        printf("Enter the length of the file %d\n", i + 1);
        scanf("%d", &lengths[i]);
    }
    
    printf("File Allocation Table\n");
    printf("File Name\tStart Block\tLength\n");
    for(i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\n", fileNames[i], startBlocks[i], lengths[i]);
    }

    return 0;
}
