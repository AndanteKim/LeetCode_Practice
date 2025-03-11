typedef long long ll;

class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size(), left = 0;
        ll ans = 0;
        unordered_map<char, int> vowelCount;    // unordered map to keep counts of vowels
        vector<int> nextConsonant(n, 0);    // Array to compute index of next consonant for all indices
        int nextConsonantIndex = n, consonantCount = 0; // Count of consonants
        for (int i = n - 1; i >= 0; --i){
            nextConsonant[i] = nextConsonantIndex;

            if (!isVowel(word[i])) nextConsonantIndex = i;
        }

        for (int right = 0; right < n; ++right){
            if (isVowel(word[right]))
                ++vowelCount[word[right]];
            else
                ++consonantCount;

            while (consonantCount > k){ 
                // Shrink window if too many consonants are present
                char newCh = word[left];
                if (isVowel(newCh)){
                    --vowelCount[newCh];
                    if (vowelCount[newCh] == 0) vowelCount.erase(newCh);
                }
                else
                    --consonantCount;
                ++left;
            }

            while (left < n \
            && vowelCount.size() == 5 \
            && consonantCount == k){
                // Try to shrink if window is valid
                ans += nextConsonant[right] - right;
                
                char startCh = word[left];
                if (isVowel(startCh)){
                    --vowelCount[startCh];
                    if (vowelCount[startCh] == 0) vowelCount.erase(startCh);
                }
                else
                    --consonantCount;
                ++left;
            }
        }

        return ans;
    }
};