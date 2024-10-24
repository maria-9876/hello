#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, rq[20], i, j, size, move, initial, total = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rq[i]);
    }

    printf("Enter the initial position: ");
    scanf("%d", &initial);

    printf("Enter size of disk: ");
    scanf("%d", &size);

    printf("Enter direction of move (1 for high, 0 for low): ");
    scanf("%d", &move);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (rq[j] > rq[j + 1])
            {
                int temp = rq[j];
                rq[j] = rq[j + 1];
                rq[j + 1] = temp;
            }
        }
    }

    int index = n;
    for (i = 0; i < n; i++)
    {
        if (initial < rq[i])
        {
            index = i;
            break;
        }
    }

    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            total += abs(rq[i] - initial);
            initial = rq[i];
        }

        total += abs(size - 1 - rq[n - 1]);
        initial=size-1;

        for (int i = index - 1; i >= 0; i--) {
            total += abs(rq[i] - initial);
            initial = rq[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            total += abs(rq[i] - initial);
            initial = rq[i];
        }

        total += abs(rq[0] - 0);
    
        initial = 0;

         for ( i = index; i < n; i++) {
            total += abs(rq[i] - initial);
            initial = rq[i];
        }
    }

    printf("Total head movement = %d\n", total);
}
