class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < n; ++i){
            bool isMatch = true;
            for (int j = 0; j < n; ++j){
                if (sortedNums[(i + j) % n] != nums[j]){
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) return true;
        }
        return false;
    }
};