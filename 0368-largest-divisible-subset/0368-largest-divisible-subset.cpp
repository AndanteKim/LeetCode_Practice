class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Base case
        int n = nums.size();
        if (n == 0) return vector<int>{};

        // Container to keep the largest divisible subset
        // ending with each of the nums
        map<int, vector<int>> EDS;
        for (int num : nums) EDS[num] = vector<int>{};
        
        // Sort the original list in ascending order
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i){
            vector<int> maxCurr;

            // Find the largest divisible subset of previous elements
            for (int k = 0; k < i; ++k){
                if (nums[i] % nums[k] == 0 && maxCurr.size() < EDS[k].size())
                    maxCurr = EDS[k];
            }

            EDS[i] = maxCurr;
            EDS[i].push_back(nums[i]);
        }

        // Find the largest of EDS values
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (ans.size() < EDS[i].size()) ans = EDS[i];

        return ans;
    }
};