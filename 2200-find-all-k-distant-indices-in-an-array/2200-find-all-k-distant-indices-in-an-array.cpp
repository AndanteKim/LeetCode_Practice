class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int r = 0;  // Unjudged index
        int n = nums.size();

        for (int j = 0; j < n; ++j){
            if (nums[j] == key){
                int l = max(r, j - k);
                r = min(n - 1, j + k) + 1;
                for (int i = l; i < r; ++i)
                    ans.push_back(i);
            }
        }

        return ans;
    }
};