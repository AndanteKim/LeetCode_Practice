class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "aeiou";
        unordered_map<char, int> vowelF, consonantF;

        for (const char& c : s){
            if (vowels.find(c) != string::npos)
                ++vowelF[c];
            else
                ++consonantF[c];
        }

        int maxVowel = 0, maxConsonant = 0;

        for (auto& [_, f] : vowelF) maxVowel = max(maxVowel, f);
        for (auto& [_, f] : consonantF) maxConsonant = max(maxConsonant, f);
        return maxVowel + maxConsonant;
    }
};