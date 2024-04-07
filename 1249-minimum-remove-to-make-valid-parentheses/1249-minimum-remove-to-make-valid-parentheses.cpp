class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Pass 1: Remove all invalid ')'
        string firstPassChars;
        int openSeen = 0, balance = 0;
        for (char& c:s){
            if (c == '('){
                ++openSeen;
                ++balance;
            }
            
            if (c == ')'){
                if (balance == 0) continue;
                --balance;
            }
            
            firstPassChars.push_back(c);
        }
        
        // Pass 2: Remove the rightmost ')'
        int openToKeep = openSeen - balance;
        string ans = "";
        for (char& c : firstPassChars){
            if (c == '('){
                --openToKeep;
                if (openToKeep < 0) continue;
            }
            ans.push_back(c);
        }
        
        return ans;
    }
};