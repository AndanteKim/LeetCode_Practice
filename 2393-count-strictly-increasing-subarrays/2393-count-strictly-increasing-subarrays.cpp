typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        //Kadane's algorithm
        int cnt = 0;
        ll ans = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            if (i && nums[i - 1] >= nums[i])
                cnt = 0;
            ++cnt;
            ans += cnt;
        }
        
        return ans;
    }
};