class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, [](Job &a, Job &b) {
            return a.profit > b.profit;
        });
        int max_deadline = -1;
        for (int i = 0; i < n; i++) {
            max_deadline = max(max_deadline, arr[i].dead);
        }
        
        vector<int> slot(max_deadline + 1, -1);
        
        int count = 0, profit = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {count, profit};
    }
};
