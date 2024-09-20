class Solution {
public:
    string shortestPalindrome(string s) {
        // KMP(Knuth Morris Pratt) algorithm
        // Reverse the original string
        string reversedStr = string(s.rbegin(), s.rend());
        
        // Combine the original and reversed strings with a separator
        string combinedStr = s + "#" + reversedStr;
        
        // Build the prefix table for the combined string
        vector<int> prefixTable = buildPrefixTable(combinedStr);
        
        // Get the length of the longest palindromic prefix
        int palindromeLength = prefixTable.back();
        
        // Construct the shortest palindrome by appending the reverse of the suffix
        string suffix = reversedStr.substr(0, s.size() - palindromeLength);
        return suffix + s;
    }
    
private:
    // Helper function to build the KMP prefix table
    vector<int> buildPrefixTable(const string& s){
        int length = 0;
        vector<int> prefixTable(s.size(), 0);
        
        // Build the table by comparing characters
        for (int i = 1; i < s.size(); ++i){
            while (length > 0 && s[i] != s[length])
                length = prefixTable[length - 1];
            
            if (s[i] == s[length]) ++length;
            
            prefixTable[i] = length;
        }
        
        return prefixTable;
    }
};