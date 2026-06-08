class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> left, mid, right;

        for (int num : nums) {
            if (num == pivot) mid.push_back(num);
            else if (num < pivot) left.push_back(num);
            else right.push_back(num);
        }

        vector<int> ans;
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), mid.begin(), mid.end());
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};