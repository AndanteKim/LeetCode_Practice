class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> counters;
        int running_sum = 0, ans = 0;
        for (const int &num: nums){
            running_sum += num;
            if (running_sum < 0){
                if ((k+(running_sum % k)) % k == 0) ++ans;
                ans += counters[(k+(running_sum % k)) % k];
                ++counters[(k+(running_sum % k)) % k];
            }
            else{
                if (running_sum % k == 0) ++ans;
                ans += counters[running_sum % k];
                ++counters[running_sum % k];
            }
            
        }
        
        return ans;
    }
};