class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), allOnes = 0, oneZero = 0, ans = 0;
        
        for (int num : nums){
            if (num == 1){
                ++allOnes;
                ++oneZero;
            }
            else{
                oneZero = allOnes;
                allOnes = 0;
            }
            
            ans = max(ans, max(allOnes, oneZero));
        }
        
        return allOnes == n? n - 1 : ans;
    }
};