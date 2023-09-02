class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stringstream ss(s);
        string word;
        while (ss >> word){
            reverse(word.begin(), word.end());
            ans += word;
            ans += " ";
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};