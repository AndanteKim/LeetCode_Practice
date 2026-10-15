class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> u;
            for (int j = i; j < n; ++j){
                u.insert(nums[j]);
                ans += u.size() * u.size();
            }
        }

        return ans;
    }
};