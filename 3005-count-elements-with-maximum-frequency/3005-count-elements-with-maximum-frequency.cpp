class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqs;
        int ans = 0, mx = 0;
        
        for (int num:nums){
            ++freqs[num];
            if (freqs[num] > mx) mx = freqs[num];
        }
        
        for (auto& [_,val]:freqs){
            if (val == mx) ans += val;
        }
        
        return ans;
    }
};