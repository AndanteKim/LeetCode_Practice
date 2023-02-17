class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        
        for (const char &c : s){
            if (!ans.empty()){
                if (ans.back() == c) ans.push_back(c);
                else if (ans.back() == c + 32 or ans.back() == c - 32) ans.pop_back();
                else ans.push_back(c);
            }
            else ans += c;
        }
        
        return ans;
    }
};