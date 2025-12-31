class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> exists(n + 1);

        for (int num : nums) {
            exists[num] = true;
        }

        vector<int> ans;
        for (int i = 1; i <= n; ++i)
            if (!exists[i]) ans.push_back(i);

        return ans; 
    }
};