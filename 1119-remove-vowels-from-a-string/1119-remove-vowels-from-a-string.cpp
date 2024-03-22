class Solution {
public:
    string removeVowels(string s) {
        string ans = "", checker = "aeiou";
        
        for (char& c:s){
            if (checker.find(c) != string::npos)
                continue;
            ans.push_back(c);
        }
        
        return ans;
    }
};