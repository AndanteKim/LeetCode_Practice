class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        for (int i1 = 0; i1 < strs[0].size(); ++i1){
            char ch = strs[0][i1];
            for (int i2 = 1; i2 < strs.size(); ++i2){
                if (i1 >= strs[i2].size() || ch != strs[i2][i1])
                    return ans;
            }
            
            ans += ch;
        }
        
        return ans;
    }
};