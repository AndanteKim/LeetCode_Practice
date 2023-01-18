class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, cnt = 0, ans = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            if (nums[right] == 0) {
                if (cnt == k){
                    while (nums[left] != 0) ++left;
                    ++left;
                }
                else ++cnt;
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};