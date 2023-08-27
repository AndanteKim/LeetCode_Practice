class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        long long num = 0;
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i){
            num = (num + word[i] - '0') % m;
            if (!num) ans[i] = 1;
            num *= 10;
        }
        
        return ans;
    }
};