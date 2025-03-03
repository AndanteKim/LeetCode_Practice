class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), lessI = 0, greaterI = n - 1;
        vector<int> ans(n);
        
        for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j){
            if (nums[i] < pivot){
                ans[lessI++] = nums[i];
            }
            
            if (nums[j] > pivot){
                ans[greaterI--] = nums[j];
            }
        }

        while (lessI <= greaterI){
            ans[lessI++] = pivot;
        }

        return ans;
    }
};