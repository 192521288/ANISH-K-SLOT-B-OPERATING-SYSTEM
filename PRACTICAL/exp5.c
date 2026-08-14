#include <stdio.h>

struct process
{
    char name;
    int burst, priority;
    int waiting, turnaround;
};

int main()
{
    int n, i, j, pos;
    struct process p[20], temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].name = 'A' + i;

        printf("\nProcess %c\n", p[i].name);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }

    /* Sort by priority: lower value = higher priority */
    for (i = 0; i < n - 1; i++)
    {
        pos = i;

        for (j = i + 1; j < n; j++)
        {
            if (p[j].priority < p[pos].priority)
                pos = j;
        }

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    p[0].waiting = 0;

    for (i = 1; i < n; i++)
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;

    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");

    for (i = 0; i < n; i++)
    {
        p[i].turnaround = p[i].waiting + p[i].burst;

        avg_wt += p[i].waiting;
        avg_tat += p[i].turnaround;

        printf("%c\t%d\t%d\t\t%d\t%d\n",
               p[i].name,
               p[i].burst,
               p[i].priority,
               p[i].waiting,
               p[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
