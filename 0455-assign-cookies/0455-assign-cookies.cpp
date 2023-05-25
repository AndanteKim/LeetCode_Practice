class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int g_i = 0, s_i = 0;
        
        while (g_i < g.size() && s_i < s.size()){
            if (g[g_i] <= s[s_i]){
                ++g_i;
                ++s_i;
                ++ans;
            }
            else ++s_i;
        }
        
        return ans;
    }
};