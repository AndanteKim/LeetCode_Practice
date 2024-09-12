class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_set<char> allowedChars(allowed.begin(), allowed.end());
        
        for (const string& word : words){
            bool flag = true;
            for (const char& c : word){
                if (!allowedChars.count(c)){
                    flag = false;
                    break;
                }
            }
            
            if (flag) ++ans;
        }
        
        return ans;
    }
};