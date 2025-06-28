class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vals;        // Auxiliary array

        for (int i = 0; i < n; ++i) vals.push_back({i, nums[i]});

        // Sort by numerical value in descending order
        sort(vals.begin(), vals.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second;});
        // Select the first k elements and sort them in ascending order by index
        sort(vals.begin(), vals.begin() + k);
        vector<int> ans;        // target subsequence
        for (int i = 0; i < k; ++i) ans.push_back(vals[i].second);

        return ans;
    }
};