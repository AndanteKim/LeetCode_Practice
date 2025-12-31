class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> valToKey;

        for (int i = 0; i < n; ++i) {
            valToKey[nums[i]].push_back(i);
        }

        sort(nums.begin(), nums.end());
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int count = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            
            for (int idx : valToKey[nums[i]])
                ans[idx] = count;
        }

        return ans;
    }
};