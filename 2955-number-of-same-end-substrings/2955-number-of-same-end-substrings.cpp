class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.size();
        // 2D vector to store prefix sum of character frequencies for each character 'a' to 'z'
        vector charFreqPrefixSum(26, vector<int>(n));
        
        // Fill the frequency vector
        for (int i = 0; i < n; ++i)
            ++charFreqPrefixSum[s[i] - 97][i];
        
        // Convert the frequency vector into a prefix sum vector
        for (auto& freq : charFreqPrefixSum){
            for (int j = 1; j < n; ++j)
                freq[j] += freq[j - 1];
        }
        
        const int numQueries = queries.size();
        vector<int> ans(numQueries);
        
        // Process each query
        for (int i = 0; i < numQueries; ++i){
            int countSameEndSubstrings = 0;
            int leftIndex = queries[i][0], rightIndex = queries[i][1];
            
            // For each character, calculate the frequency of occurrences within the query range
            for (auto& freq : charFreqPrefixSum){
                // Calculate frquency within the query range
                int leftFreq = (queries[i][0] == 0)? 0 : freq[leftIndex - 1];
                int rightFreq = freq[rightIndex];
                int frequencyInRange = rightFreq - leftFreq;
                
                // Calculate the number of same-end substrings for this character.
                countSameEndSubstrings += (frequencyInRange * (frequencyInRange + 1) >> 1);
            }
            
            ans[i] = countSameEndSubstrings;
        }
        
        return ans;
    }
};