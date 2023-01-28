class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, cnts = 0, ans = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            if (nums[right] & 1){
                --k;
                cnts = 0;
            }
            while (k == 0){
                k = nums[left] & 1;
                ++left;
                ++cnts;
            }
            ans += cnts;
        }
        return ans;
    }
};