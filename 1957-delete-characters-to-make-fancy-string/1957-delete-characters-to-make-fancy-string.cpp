class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        
        for (const char& c : s){
            ans.push_back(c);
            
            if (ans.size() >= 3 && ans.back() == ans[ans.size() - 2] && ans[ans.size() - 2] == ans[ans.size() - 3])
                ans.pop_back();
        }
        
        return ans;
    }
};