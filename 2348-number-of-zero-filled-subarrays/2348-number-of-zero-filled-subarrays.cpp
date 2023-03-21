class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, num_subarray = 0;
        
        for (int num : nums){
            if (num == 0){
                ++num_subarray;
            }
            else{
                num_subarray = 0;
            }
            ans += num_subarray;
        }
        return ans;
    }
};