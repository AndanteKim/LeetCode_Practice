class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        // Use hashmap(unordered_map) to find count of words
        unordered_map<string, int> freq1, freq2;
        for (const auto& w : words1)
            ++freq1[w];
        for (const auto& w : words2)
            ++freq2[w];
        
        int ans = 0;
        // Find the common words and the both frequency of common words is 1.
        for (auto& [word, freq] : freq1){
            if (freq == 1 && freq2[word] == 1)
                ++ans;
        }
        
        return ans;
    }
};