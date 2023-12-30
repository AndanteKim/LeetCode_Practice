class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> chars(26);
        int n = words.size();
        
        for (string& word: words){
            for (char& c: word){
                ++chars[c - 97];
            }
        }
        
        for (int i = 0; i < 26; ++i){
            if (chars[i] % n != 0)
                return false;
        }
        
        return true;
    }
};