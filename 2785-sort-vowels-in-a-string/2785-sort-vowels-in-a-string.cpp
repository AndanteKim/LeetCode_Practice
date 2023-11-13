class Solution {
private:
    bool isVowel(char& c){
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||\
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
public:
    string sortVowels(string s) {
        unordered_map<char, int> count;
        for (char& c : s){
            if (isVowel(c))
                ++count[c];
        }
        
        string ans = "", sortedVowels = "AEIOUaeiou";
        int j = 0;
        
        for (int i = 0; i < s.size(); ++i){
            if (isVowel(s[i])){
                while (count[sortedVowels[j]] == 0) ++j;
                ans += sortedVowels[j];
                --count[sortedVowels[j]];
            }
            else
                ans.push_back(s[i]);
        }
        
        return ans;
    }
};