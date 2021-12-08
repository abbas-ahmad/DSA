/*
    Given a set of N jobs where each jobi has a deadline and profit associated with it.
    Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
    We earn the profit associated with job if and only if the job is completed by its deadline.
    Find the number of jobs done and the maximum profit.
    Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

    https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

    idea:
    - sort the jobs by profit and try to finish the jobs at late as possible
    - this will ensure that we will finish max number of jobs with max profit
*/

bool comp(Job j1, Job j2){
        return j1.profit > j2.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n);
        
        int maxDeadline = arr[0].dead;
        for(int i = 1; i < n; i++){
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        //map Deadline d: Slot:d-1 index
        vector<int> slots(maxDeadline, -1);
        int jobsFinished = 0;
        int profit = 0;
        
        for(int k = 0; k < n; k++){
            int i = arr[k].dead - 1;
            while(i >= 0 and slots[i] != -1) i--;
            
            if(i == -1) continue;
            else {
                slots[i] = arr[k].id;
                profit += arr[k].profit;
                jobsFinished++;
            }
            
            // if all slots filled
            if(jobsFinished == maxDeadline) break;
        }
        vector<int> ans;
        ans.push_back(profit);
        ans.push_back(jobsFinished);
        return ans;
    } 