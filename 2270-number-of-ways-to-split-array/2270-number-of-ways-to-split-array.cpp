
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        
        for (const int &num: nums) total += num;
        long long curr = 0, cnt = 0;
        
        for (int i = 0; i <= nums.size()-2; ++i){
            curr += nums[i];
            
            if (curr >= total - curr) ++cnt;
        }
        return cnt;
    }
};