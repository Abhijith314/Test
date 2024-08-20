#include<stdio.h>
struct data {
int p_no, bt_tm, tat, wt, at_tm, priority;
} a[20], temp;
void main() {
int n, i, j, completed = 0, current_time = 0, min_index;
float twt = 0, ttat = 0, atat, awt;
printf("Enter the number of processes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
printf("Enter the process no, Burst time, Arrival time, and Priority: ");
scanf("%d %d %d %d", &a[i].p_no, &a[i].bt_tm, &a[i].at_tm, &a[i].priority);
}
for (i = 0; i < n; i++) {
for (j = i + 1; j < n; j++) {
if (a[i].at_tm > a[j].at_tm || 
(a[i].at_tm == a[j].at_tm && a[i].priority > a[j].priority)) {
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}
while (completed < n) {
min_index = -1;
for (i = 0; i < n; i++) {
if (a[i].at_tm <= current_time && a[i].bt_tm > 0) {
if (min_index == -1 || a[i].priority < a[min_index].priority) {
min_index = i;
}
}
}
if (min_index == -1) {
current_time++;
} 
else {
current_time += a[min_index].bt_tm;
a[min_index].tat = current_time - a[min_index].at_tm;
a[min_index].wt = a[min_index].tat - a[min_index].bt_tm;
ttat += a[min_index].tat;
twt += a[min_index].wt;
a[min_index].bt_tm = 0;
completed++;
}
}
atat = ttat / n;
awt = twt / n;
printf("\nProcess id\tArrival time\tBurst time\tPriority\tTA_T\tW_T\n");
for (i = 0; i < n; i++) {
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a[i].p_no, a[i].at_tm, a[i].tat + a[i].wt, a[i].priority, a[i].tat, a[i].wt);
}
printf("Average turn around time = %f\n", atat);
printf("Average waiting time = %f\n", awt);
printf("GANTT CHART\n");
current_time = 0;
for (i = 0; i < n; i++) {
if (current_time < a[i].at_tm) {
current_time = a[i].at_tm;
}
printf("P%d\t%d ", a[i].p_no, current_time + a[i].tat);
current_time += a[i].tat;
}
printf("\n");
}
