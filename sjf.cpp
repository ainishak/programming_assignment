/* Name : Amirah Binti Masri
Matric No : 1813198 */

#include<bits/stdc++.h>

using namespace std;
 
struct Process
{
   int ccode;     // coursecode
   int duration;     
   int priority;
   int arrival_time;
};
 
/* 
    this function is used for sorting all
    processes in increasing order of duration
*/
bool comparison(Process a, Process b)
{
    return (a.duration < b.duration);
}
 
// function to find the waiting time for all processes
void findWaitingTime(Process proc[], int n, int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] = proc[i-1].duration + wt[i-1] ;
    }
}
 
// function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    // calculating turnaround time by adding duration[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = proc[i].duration + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(proc, n, wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);
 
    // display processes along with all details
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].ccode << "\t\t"
             << proc[i].duration << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
 
// main function
int main()
{
    Process proc[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};
    int n = sizeof proc / sizeof proc[0];
 
    // sorting processes by duration.
    sort(proc, proc + n, comparison);
 
    cout << "Order in which process gets executed\n";
    for (int i = 0 ; i < n; i++)
    {
        cout << proc[i].duration <<" ";
    }
 
    findAverageTime(proc, n);
    
    return 0;
}
