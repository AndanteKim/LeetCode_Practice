class Solution {
public:
    string reorganizeString(string s) {
        vector<int> alphabets(26);
        for (char& c : s) ++alphabets[c - 'a'];
        
        int maxCount = 0, letter = 0, index = 0;
        for (int i = 0; i < 26; ++i){
            if (alphabets[i] > maxCount){
                maxCount = alphabets[i];
                letter = i;
            }
        }
        
        if (maxCount > (s.size() + 1) / 2) return "";
        
        string ans = s;
        while (alphabets[letter] != 0){
            ans[index] = char(letter + 'a');
            index += 2;
            --alphabets[letter];
        }
        
        for (int i = 0; i < 26; ++i){
            while (alphabets[i] != 0){
                if (index >= s.size()) index = 1;
                ans[index] = char(i + 'a');
                index += 2;
                --alphabets[i];
            }
        }
        
        return ans;
    }
};