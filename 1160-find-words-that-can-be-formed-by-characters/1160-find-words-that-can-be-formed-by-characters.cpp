class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> countChars(26);
        int ans = 0;
        for (char& c:chars)
            ++countChars[c - 97];
        
        for (string& word:words){
            bool available = true;
            vector<int> remainChars = countChars;
            for (char& c:word){
                if (remainChars[c - 97] == 0){
                    available = false;
                    break;
                }
                --remainChars[c - 97];
            }
            
            if (available)
                ans += word.size();
        }
        
        return ans;
    }
};