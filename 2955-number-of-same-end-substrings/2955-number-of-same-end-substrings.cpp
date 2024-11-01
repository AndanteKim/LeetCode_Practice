class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        // Map to store each character and its positions in the string 's'.
        int n = s.size();
        unordered_map<char, vector<int>> characterPositionsMapping;
        
        // Traverse the string and store the index of each character in the map
        for (int i = 0; i < n; ++i)
            characterPositionsMapping[s[i]].push_back(i);
        
        // Array to store the result for each query
        int numQueries = queries.size();
        vector<int> ans(numQueries);
        
        // Process each query
        for (int i = 0; i < numQueries; ++i){
            int leftIndex = queries[i][0], rightIndex = queries[i][1], countSameEndSubstrings = 0;
            
            // For each unique character in the string, calculate the number of same-end substrings
            for (auto& [_, positions] : characterPositionsMapping){
                // Get the number of occurrences of the character within the range [leftIndex, rightIndex];
                int leftBound = lower_bound(positions.begin(), positions.end(), leftIndex) - positions.begin();
                int rightBound = upper_bound(positions.begin(), positions.end(), rightIndex) - positions.begin();
                int numOccurrences = (rightBound - leftBound);
                
                // Calculate the number of same-end substrings for this character
                countSameEndSubstrings += ((numOccurrences * (numOccurrences + 1)) >> 1);
            }
            
            // Store the result for this query.
            ans[i] = countSameEndSubstrings;
        }
        
        return ans;
    }
};