class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Initialize results with an empty string
        // from which to build all future results
        vector<string> results{""};
        int ans = 0;
        
        for (string& word: arr){
            // We only want to iterate through results
            // that existed prior to this loop
            for (int i = 0; i < results.size(); ++i){
                // Form a new result combination and
                // use a set to check for duplicate characters
                string newResults = results[i] + word;
                unordered_set<int> chars;
                for (char& c:newResults)
                    chars.insert(c);
                if (newResults.size() != chars.size())
                    continue;
                
                // Add valid options to results and
                // keep track of the longest so far
                results.push_back(newResults);
                ans = max(ans, (int)newResults.size());
            }
        }
        
        return ans;
    }
};