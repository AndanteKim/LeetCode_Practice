class Solution {
private:
    int n;
    void abbreviated(vector<string>& abbreviations, const string& word, string currWord, int index, int abbreviatedCount){
        // Base case
        if (index == n){
            // If the length of the last abbreviated substring is 0, add an empty string.
            if (abbreviatedCount > 0)
                currWord += to_string(abbreviatedCount);
            abbreviations.push_back(currWord);
            return;
        }
        
        // Option 1: Keep the current character 
        string abbreviatedString = (abbreviatedCount > 0)? to_string(abbreviatedCount) : "";
        abbreviated(abbreviations, word, currWord + abbreviatedString + word[index], index + 1, 0);
        
        // Option 2: Abbreviate the current character
        abbreviated(abbreviations, word, currWord, index + 1, abbreviatedCount + 1);
    }
    
    
public:
    vector<string> generateAbbreviations(string word) {
        this -> n = word.size();
        vector<string> abbreviations;
        
        abbreviated(abbreviations, word, "", 0, 0);
        return abbreviations;
    }
};