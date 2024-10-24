#include <stdio.h>

int main() {
    int n, i, j, k;
    
    printf("Enter the number of files to be added:\n");
    scanf("%d", &n);
    
    int startAddresses[n];
    int lengths[n];
    int numBlocks[n];
    int blocks[n][20];
    
    for(i = 0; i < n; i++) {
        printf("Enter the start address of file[%d]:\n", i);
        scanf("%d", &startAddresses[i]);
        printf("Enter the length of the file[%d]:\n", i);
        scanf("%d", &lengths[i]);
        printf("Enter the number of blocks of file[%d]:\n", i);
        scanf("%d", &numBlocks[i]);
        printf("Enter the blocks allocated:\n");
        for(j = 0; j < numBlocks[i]; j++) {
            scanf("%d", &blocks[i][j]);
        }
    }
    
    printf("\nFile Allocation Table:\n");
    for(i = 0; i < n; i++) {
        printf("file no: %d \t no of blocks: %d \t length: %d \t start addr: %d\n", 
               i, numBlocks[i], lengths[i], startAddresses[i]);
    }
    
    while(1) {
        printf("\n1. Get the blocks\n2. exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 2) {
            break;
        }
        
        printf("Enter the file number:\n");
        int fileNumber;
        scanf("%d", &fileNumber);
        
        if (fileNumber < 0 || fileNumber >= n) {
            printf("Invalid file number\n");
            continue;
        }
        
        printf("Blocks allocated: ");
        for(k = 0; k < numBlocks[fileNumber]; k++) {
            printf("%d ", blocks[fileNumber][k]);
        }
        printf("\n");
    }
    
    return 0;
}
