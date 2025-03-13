class Solution {
private:
    int n;
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k){
        int total = 0;
        vector<int> diffArray(n + 1);

        // Process query
        for (int qIndex = 0; qIndex < k; ++qIndex){
            int start = queries[qIndex][0], end = queries[qIndex][1], val = queries[qIndex][2];

            // Process start and end of range
            diffArray[start] += val;
            diffArray[end + 1] -= val;
        }

        // Check if zero array can be formed
        for (int index = 0; index < n; ++index){
            total += diffArray[index];
            if (total < nums[index])
                return false;
        }

        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        this -> n = nums.size();
        int left = 0, right = queries.size();

        // Base case: Zero array isn't formed after all queries are processed
        if (!canFormZeroArray(nums, queries, right)) return -1;

        // Binary Search
        while (left <= right){
            int mid = left + ((right - left) >> 1);

            if (canFormZeroArray(nums, queries, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Return the earliest query that zero array can be formed
        return left;
    }
};