class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long left_section = 0, total = 0, right_section;
        for (const int &num: nums) total += num;
        
        for (int i = 0; i < nums.size()-1; ++i){
            left_section += nums[i];
            right_section = total - left_section;
            if (left_section >= right_section) ++ans;
        }
        
        return ans;
    }
};