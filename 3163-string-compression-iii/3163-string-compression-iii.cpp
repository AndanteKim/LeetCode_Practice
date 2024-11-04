class Solution {
public:
    string compressedString(string word) {
        unordered_map<char, int> frequency;
        int n = word.size();
        char prev = NULL;
        string ans = "";
        
        for (int i = 0; i < n; ++i){
            // If the current character doesn't match previous character, then compression the previous one before getting current one.
            if (prev != NULL && prev != word[i]){
                while (frequency[prev] > 0){
                    ans += to_string(min(frequency[prev], 9)) + prev;
                    frequency[prev] -= min(frequency[prev], 9);
                }
            }
            
            ++frequency[word[i]];
            prev = word[i];
            
            // If the index is the last character, then finish compressing the last character's frequency.
            if (i == n - 1){
                while (frequency[word[i]] > 0){
                    ans += to_string(min(frequency[word[i]], 9)) + word[i];
                    frequency[word[i]] -= min(frequency[word[i]], 9);
                }
            }
        }
        
        return ans;
    }
};