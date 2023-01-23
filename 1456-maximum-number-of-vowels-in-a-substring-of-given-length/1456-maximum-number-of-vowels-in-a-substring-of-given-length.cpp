class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0, max_vowel = 0;
        string vowels = "aeiou";
        for (const auto &c: s.substr(0,k)) if (vowels.find(c) != string::npos) ++max_vowel;
        
        int curr = max_vowel;
        for (int right = k; right < s.size(); ++right){
            if (vowels.find(s[right]) != string::npos) ++curr;
            if (vowels.find(s[left]) != string::npos) --curr;
            ++left;
            max_vowel = max(max_vowel, curr);
        }
        
        return max_vowel;
    }
};