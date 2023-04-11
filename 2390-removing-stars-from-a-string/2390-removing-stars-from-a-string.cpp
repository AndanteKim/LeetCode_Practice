class Solution {
public:
    string removeStars(string s) {
        string ans;
        for (const char &c : s){
            if (c != '*') ans.push_back(c);
            else if (ans != "") ans.pop_back();
        }
        return ans;
    }
};