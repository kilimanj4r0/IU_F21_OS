#include "stdio.h"
#define max(a,b) (a < b ? b : a)
#define min(a,b) (a > b ? b : a)

int main(int argc, char *argv[]) {
    int n; // number of processes passed by program parameter
    sscanf(argv[1], "%d", &n);
    int q; // quantum
    int at[n]; // arrival time for each process
    int bt[n]; // burst time for each process
    int ct[n]; // completion time for each process
    int tat[n]; // turn around time for each process
    int wt[n]; // waiting time for each process
    int pid[n]; // process id for each process
    int done[n]; // boolean that indicates finishing for each process 
    int iter[n]; // number of waves for each process
    double avg_tat; // average turn around time
    double avg_wt; // average waiting time

    for (int i = 0; i < n; i++) {
        pid[i] = i;
        done[i] = 0;
        iter[i] = 0;
        printf("Enter the arrival time for process[%d]: ", i);
        scanf("%d", &at[i]);
        printf("Enter the burst time for process[%d]: ", i);
        scanf("%d", &bt[i]);
    }
    printf("Enter the quantum: ");
    scanf("%d", &q);

    // Sorting processes by arrival time
    for (int i = 0 ; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (at[j] > at[j+1]) {
                int temp_at = at[j];
                int temp_bt = bt[j];
                int temp_pid = pid[j];
                at[j] = at[j+1];
                bt[j] = bt[j+1];
                pid[j] = pid[j+1];
                at[j+1] = temp_at;
                bt[j+1] = temp_bt;
                pid[j+1] = temp_pid;
            }
        }
    }

    // CT, TAT, WT
    int cur_time = 0;
    int have_unfinished_processes = 1;
    int temp_bt[n];
    for (int i = 0; i < n; i++) {
        temp_bt[i] = bt[i];
    }
    while(have_unfinished_processes) {

        have_unfinished_processes = 0;

        for (int i = 0; i < n; i++) {
            if (done[i]) {
                continue;
            }
            iter[i] = iter[i] + 1;
            cur_time = max(cur_time, at[i]);

            ct[i] = min(temp_bt[i], q) + cur_time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - min(temp_bt[i], q);
            if (iter[i] > 1) {
                wt[i] = wt[i] - q * (iter[i] - 1);
            }

            temp_bt[i] = temp_bt[i] - min(temp_bt[i], q);
            if (temp_bt[i] == 0) {
                done[i] = 1;
            }
            cur_time = ct[i];
        }
        for (int i = 0; i < n; i++) {
            if (done[i] == 0) {
                have_unfinished_processes = 1;
            }
        }

    }

    // Average TAT, WT
    double t_tat = 0, t_wt = 0;
    for (int i = 0; i < n; i++) {
        t_tat += tat[i];
        t_wt += wt[i];
    }
    avg_tat = t_tat / n;
    avg_wt = t_wt / n;

    // output
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average TAT: %.2f\n", avg_tat);
    printf("Average WT: %.2f\n", avg_wt);
    return 0;
}