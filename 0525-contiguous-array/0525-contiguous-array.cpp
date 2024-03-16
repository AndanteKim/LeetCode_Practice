class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(2 * n + 1, -2);
        arr[n] = -1;
        int ans = 0, count = 0;
        
        for (int i = 0; i < n; ++i){
            count += (nums[i] == 0)? -1 : 1;
            
            if (arr[count + n] >= -1){
                ans = max(ans, i - arr[count + n]);
            }
            else
                arr[count + n] = i;
        }
        
        return ans;
    }
};