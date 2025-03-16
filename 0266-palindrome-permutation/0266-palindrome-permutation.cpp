class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> freq;
        for (const auto& c : s){
            ++freq[c];
        }

        int countOdd = 0;

        // Count the number of odds
        for (auto& [c, val] : freq){
            countOdd += val % 2;
        }
        
        return countOdd <= 1;
    }
};