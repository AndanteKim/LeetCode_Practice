class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int start = 0;
        for (int space: spaces){
            ans += s.substr(start, space - start) + " ";
            start = space;
        }
        
        string lastWord = s.substr(start);
        ans = lastWord.empty()? ans.substr(0, ans.size() - 1) : ans + lastWord;
        
        return ans;
    }
};