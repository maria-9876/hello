#include <stdio.h>

 int frameno, pageno, counts[20],i,j;
    int pages[20], frames[20];int pagefault=0;

void printFrames(int frames[], int frameno) {
    for (int i = 0; i < frameno; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

int findLFU()
{
    
    int min=counts[0];
    int lfuframe=0;
    for(int i=0;i<frameno;i++)
    {
        if(counts[i]<min)
        {
            min=counts[i];
            lfuframe=i;
        }
    }
    return lfuframe;
}
int main() {
   
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
        counts[i]=0;
    }
     for (i = 0; i < pageno; i++)
     {
        int found = 0;
        for (j = 0; j < frameno; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                counts[j]++;
                break;
            }
        }
    if(found==0)
    {
        int lfuframe=findLFU();
        frames[lfuframe]=pages[i];
        counts[lfuframe]=1;
        pagefault++;
        
    }
    printFrames(frames, frameno);
}
 printf("The total number of page faults using LFU are: %d\n", pagefault);
return 0;
}
