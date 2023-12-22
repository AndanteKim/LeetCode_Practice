class Solution {
public:
    int maxScore(string s) {
        int ans = 0, left = (s[0] == '0')? 1:0, right = (s[0] == '1')? count(s.begin(), s.end(), '1') - 1 : count(s.begin(), s.end(), '1');
        ans = max(ans, left + right);
        
        for (int i = 1; i < s.size() - 1; ++i){
            if (s[i] == '0')
                ++left;
            else
                --right;
            ans = max(ans, left + right);
        }
        
        return ans;
    }
};