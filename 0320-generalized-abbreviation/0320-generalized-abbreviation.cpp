class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<string> abbreviations;
        
        for (int mask = 0; mask < (1 << n); ++mask){
            string currWord = "";
            int abbreviatedCount = 0;
            for (int index = 0; index < n; ++index){
                // If the bit at the position index is 1, increment the abbreviated substring.
                if (mask & (1 << index))
                    ++abbreviatedCount;
                
                else{
                    // Append the last substring and then the current character.
                    if (abbreviatedCount > 0){
                        currWord += to_string(abbreviatedCount);
                        abbreviatedCount = 0;
                    }
                    currWord.push_back(word[index]);
                }
            }
            
            if (abbreviatedCount > 0)
                currWord += to_string(abbreviatedCount);
            abbreviations.push_back(currWord);
        }
        
        return abbreviations;
    }
};