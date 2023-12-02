class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        vector<int> count(1001);
        for (int num:nums)
            ++count[num];
        
        int ans = -1, lo = 1, hi = 1000;
        while (lo <= hi){
            if (lo + hi >= k || count[hi] == 0)
                --hi;
            else{
                if (count[lo] > (lo < hi? 0:1))
                    ans = max(ans, lo + hi);
                ++lo;
            }
        }
        return ans;
    }
};