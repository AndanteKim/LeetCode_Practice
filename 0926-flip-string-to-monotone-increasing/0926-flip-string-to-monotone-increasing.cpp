class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int sum_cnt = 0, ans;
        
        for (const auto &c: s) if (c == '0') ++sum_cnt;
        ans = sum_cnt;
        for (const auto &c: s){
            if (c == '0') {
                --sum_cnt;
                ans = min(ans, sum_cnt);
            }
            else ++sum_cnt;
        }
        
        return ans;
        
    }
};