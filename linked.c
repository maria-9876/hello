#include <stdio.h>

int main() {
    int allocatedBlocks[100], n, i, j, numBlocks, startBlock;

    printf("Enter the number of blocks which are already allocated:\n");
    scanf("%d", &n);
    
    printf("Enter the blocks which are already allocated:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &allocatedBlocks[i]);
    }
    
    while (1) {
        int choice;
        
        printf("\n1. add file\n2. exit\n");
        scanf("%d", &choice);
        
        if (choice == 2) {
            break;
        }
        
        printf("Enter the no of blocks to be allocated and starting block:\n");
        scanf("%d %d", &numBlocks, &startBlock);
        
        int blockNum = startBlock;
        
        for (i = 0; i < numBlocks; i++) {
            while (1) {
                int allocated = 0;
                for (j = 0; j < n; j++) {
                    if (allocatedBlocks[j] == blockNum) {
                        allocated = 1;
                        break;
                    }
                }
                
                if (!allocated) {
                    allocatedBlocks[n++] = blockNum;
                    printf("bno: %d ---->1\n", blockNum);
                    blockNum++;
                    break;
                } else {
                    blockNum++;
                }
            }
        }
    }
    
    return 0;
}
