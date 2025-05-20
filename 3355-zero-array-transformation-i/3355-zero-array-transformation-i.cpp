class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> deltas(n + 1);

        for (const auto& query : queries){
            int left = query[0], right = query[1];
            ++deltas[left];
            --deltas[right + 1];
        }

        int currOperations = 0;
        vector<int> operationCounts(n + 1);
        for (int i = 0; i <= n; ++i){
            currOperations += deltas[i];
            operationCounts[i] = currOperations;
        }

        for (int i = 0; i < n; ++i)
            if (operationCounts[i] < nums[i]) return false;

        return true;
    }
};