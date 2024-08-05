class Solution
{
    public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Step 1: Replace negative numbers, zeros, and numbers larger than n with n+1
        // (which is out of range). We only care about numbers in the range 1 to n.
        for(int i = 0; i < n; i++) {
            if(arr[i] <= 0 || arr[i] > n) arr[i] = n + 1;
        }

        // Step 2: Use the index as a hash key and mark the corresponding positions.
        for(int i = 0; i < n; i++) {
            int currElement = abs(arr[i]);
            if(currElement >= 1 && currElement <= n) {
                int index = currElement - 1;
                // Mark the element at this index as negative to indicate presence
                if(arr[index] > 0) arr[index] = -arr[index];
            }
        }

        // Step 3: The first positive index+1 is our answer, as it's the first missing positive number.
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                return i + 1;
            }
        }

        // If all indices are marked, then the smallest missing positive is n+1
        return n + 1;
    } 
};
