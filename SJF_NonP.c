#include<stdio.h>
struct data {
int p_no,bt_tm,tat,wt,at_tm;
} a[20],temp;
void main() 
{
int n,i,j,tta=0,current_time=0;
float twt=0,ttat=0,atat,awt;
printf("Enter the number of processes: ");
scanf("%d",&n);
for (i=0;i<n;i++) {
printf("Enter the process no, Burst time, and Arrival time: ");
scanf("%d %d %d", &a[i].p_no,&a[i].bt_tm,&a[i].at_tm);
}
for (i=0;i<n;i++) {
for (j=i+1;j<n;j++) {
if (a[i].at_tm>a[j].at_tm || (a[i].at_tm==a[j].at_tm && a[i].bt_tm>a[j].bt_tm)) {
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
for (i=0;i<n;i++) {
if (current_time < a[i].at_tm) {
current_time=a[i].at_tm;
}
a[i].tat=current_time+a[i].bt_tm-a[i].at_tm;
a[i].wt=current_time-a[i].at_tm;
current_time+=a[i].bt_tm;
ttat+=a[i].tat;
twt+=a[i].wt;
}
atat=ttat/n;
awt=twt/n;
printf("\nProcess id\tArrival time\tBurst time\tTA_T\tW_T\n");
for (i = 0; i < n; i++) {
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a[i].p_no,a[i].at_tm,a[i].bt_tm,a[i].tat,a[i].wt);
}
printf("Average turn around time = %f\n",atat);
printf("Average waiting time = %f\n",awt);
printf("GANTT CHART\n0");
current_time=0;
for (i=0;i<n;i++) {
if (current_time<a[i].at_tm) {
current_time=a[i].at_tm;
}
printf("\tP%d\t%d",a[i].p_no,current_time+a[i].bt_tm);
current_time+=a[i].bt_tm;
}
printf("\n");
}
