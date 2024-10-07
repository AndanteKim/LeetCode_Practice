class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, count = 0;
        vector<int> arr(2 * n + 1, -2);
        arr[n] = -1;
        
        for (int i = 0; i < n; ++i){
            count += (nums[i] == 1)? 1 : -1;
            
            if (arr[count + n] >= -1)
                maxLen = max(maxLen, i - arr[count + n]);
            else
                arr[count + n] = i;
        }
        
        return maxLen;
    }
};