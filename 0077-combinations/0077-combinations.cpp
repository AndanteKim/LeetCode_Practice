class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= k; ++i) nums.push_back(i);
        nums.push_back(n + 1);
        vector<vector<int>> ans;
        int j = 0;
        while (j < k){
            vector<int> curr(nums.begin(), nums.begin() + k);
            ans.push_back(curr);
            j = 0;
            while (j < k && nums[j + 1] == nums[j] + 1){
                nums[j] = j + 1;
                ++j;
            }
            ++nums[j];
        }
        return ans;
    }
};