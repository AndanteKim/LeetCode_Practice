class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> c;
        
        for (int n:nums) ++c[n];
        
        int ans = 0, need = 0;
        for (auto& [x, freq] : c){
            ans += freq * max(need - x, 0) + ((freq * (freq - 1)) >> 1);
            need = max(need, x) + freq;
        }
        
        return ans;
    }
};