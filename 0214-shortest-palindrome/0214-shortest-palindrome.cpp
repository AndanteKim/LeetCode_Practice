class Solution {
private:
    string preprocessString(string &s){
        // Add boundaries and separators to handle palindromes uniformly
        string modifiedS = "^";
        for (const char& c : s){
            modifiedS += "#" + string(1, c);
        }
        modifiedS += "#$";
        return modifiedS;
    }
    
public:
    string shortestPalindrome(string s) {
        // Manacher algorithm
        // Base case: Return early if the string is null or empty
        if (s.empty()) return "";
        
        // Preprocess the string to handle palindromes uniformly
        string modifiedS = preprocessString(s);
        int n = modifiedS.size();
        vector<int> palindromeRadiusArray(n);
        int center = 0, rightBoundary = 0, maxPalindromeLength = 0;
        
        // Iterate through each character in the modified string
        for (int i = 1; i < n - 1; ++i){
            int mirrorIndex = 2 * center - i;
            
            // Use previously computed values to avoid redundant calculations
            if (rightBoundary > i)
                palindromeRadiusArray[i] = min(rightBoundary - i, palindromeRadiusArray[mirrorIndex]);
            
            // Expand around the current center while characters match
            while (modifiedS[i + 1 + palindromeRadiusArray[i]] == modifiedS[i - 1 - palindromeRadiusArray[i]])
                ++palindromeRadiusArray[i];
            
            // Update the center and right boundary if the palindrome extends beyond the current boundary
            if (i + palindromeRadiusArray[i] > rightBoundary){
                center = i;
                rightBoundary = i + palindromeRadiusArray[i];
            }
            
            // Update the maximum length of palindrome starting at the beginning
            if (i - palindromeRadiusArray[i] == 1)
                maxPalindromeLength = max(maxPalindromeLength, palindromeRadiusArray[i]);
        }
        
        // Constuct the shortest palindrome by reverseing the suffix and prepending it to the original string.
        string reverseSuffix = s.substr(maxPalindromeLength);
        reverse(reverseSuffix.begin(), reverseSuffix.end());
        
        return reverseSuffix + s;
    }
};