#include <stdio.h>
#include <stdlib.h>

struct Process{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
};

int arrivalTimeCompare(const void *a, const void *b){
    return ((struct Process *)a)->arrival_time - ((struct Process *)b)->arrival_time;
};

int burstTimeCompare(const void *a, const void *b){
    if (((struct Process *)a)->burst_time == ((struct Process *)b)->burst_time){
        return ((struct Process *)a)->arrival_time - ((struct Process *)b)->arrival_time;
    };
    return ((struct Process *)a)->burst_time - ((struct Process *)b)->burst_time;
};

void fcfs(struct Process processes[], int n){
    int time = 0;
    int waitingTimeTotal = 0;
    int turnaroundTimeTotal = 0;
    int responseTimeTotal = 0;

    qsort(processes, n, sizeof(struct Process), arrivalTimeCompare);

    printf("=== First Come First Served (FCFS) ===\n");
    printf("Gantt Chart: ");

    for (int i = 0; i < n; i++){
        processes[i].waiting_time = time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        processes[i].response_time = processes[i].waiting_time;

        waitingTimeTotal += processes[i].waiting_time;
        turnaroundTimeTotal += processes[i].turnaround_time;
        responseTimeTotal += processes[i].response_time;

        printf("| P%d |", processes[i].pid);
        time += processes[i].burst_time;
    }

        printf("\n");
        printf("PID\tAT\tBT\tWT\tTAT\tRT\n");

        for (int i = 0; i < n; i++){
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                   processes[i].pid,
                   processes[i].arrival_time,
                   processes[i].burst_time,
                   processes[i].waiting_time,
                   processes[i].turnaround_time,
                   processes[i].response_time);
        }

        printf("\nAverage Waiting Time: %.2f\n", (double)waitingTimeTotal / n);
        printf("Average Turnaround Time: %.2f\n", (double)turnaroundTimeTotal / n);
        printf("Average Response Time: %.2f\n", (double)responseTimeTotal / n);
    }

void sjf(struct Process processes[], int n){
    int time = 0;
    int waitingTimeTotal = 0;
    int turnaroundTimeTotal = 0;
    int responseTimeTotal = 0;

    qsort(processes, n, sizeof(struct Process), burstTimeCompare);

    printf("=== Shortest Job First (SJF) ===\n");
    printf("Gantt Chart: ");

    for (int i = 0; i < n; i++){
        processes[i].waiting_time = time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        processes[i].response_time = processes[i].waiting_time;

        waitingTimeTotal += processes[i].waiting_time;
        turnaroundTimeTotal += processes[i].turnaround_time;
        responseTimeTotal += processes[i].response_time;

        printf("| P%d |", processes[i].pid);
        time += processes[i].burst_time;
    }

        printf("\n");
        printf("PID\tAT\tBT\tWT\tTAT\tRT\n");

        for (int i = 0; i < n; i++){
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                   processes[i].pid,
                   processes[i].arrival_time,
                   processes[i].burst_time,
                   processes[i].waiting_time,
                   processes[i].turnaround_time,
                   processes[i].response_time);
        }

        printf("\nAverage Waiting Time: %.2f\n", (double)waitingTimeTotal / n);
        printf("Average Turnaround Time: %.2f\n", (double)turnaroundTimeTotal / n);
        printf("Average Response Time: %.2f\n", (double)responseTimeTotal / n);
};

int main(){
    struct Process processes[20];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > 20)
    {
        printf("Too many processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    fcfs(processes, n);
    sjf(processes, n);

    return 0;
}