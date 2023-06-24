class Solution {
private:
    void backtrack(int start, string& addr, int boundary, string& s, vector<string>& ans){
        if (boundary == 0){
            if (start == s.size()) ans.push_back(addr.substr(0, addr.size() - 1));
            return;
        }
        
        if (start + 1 <= s.size()){
            addr = addr + s[start] + '.';
            backtrack(start + 1, addr, boundary - 1, s, ans);
            for (int i = 0; i < 2; ++i) addr.pop_back();
        }
    
        if (start + 2 <= s.size() && s[start] != '0'){
            addr = addr + s[start] + s[start + 1] + '.';
            backtrack(start + 2, addr, boundary - 1, s, ans);
            for (int i = 0; i < 3; ++i) addr.pop_back();
        }
        if (start + 3 <= s.size() && s[start] != '0' && stoi(s.substr(start, 3)) >= 0 && stoi(s.substr(start, 3)) <= 255){
            addr = addr + s[start] + s[start + 1] + s[start + 2] + '.';
            backtrack(start + 3, addr, boundary - 1, s, ans);
            for (int i = 0; i < 4; ++i) addr.pop_back();
        }
            
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string addr = "";
        backtrack(0, addr, 4, s, ans);
        return ans;
    }
};