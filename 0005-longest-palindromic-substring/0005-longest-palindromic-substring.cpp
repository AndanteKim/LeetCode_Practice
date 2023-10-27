class Solution {
public:
    string longestPalindrome(string s) {
        string sPrime = "#";
        for (char& c : s){
            sPrime += c;
            sPrime += '#';
        }
        
        int n = sPrime.size(), center = 0, radius = 0;
        vector<int> palindromeRadii(n);
        pair<int, int> ans;
        
        for (int i = 0; i < n; ++i){
            int mirror = 2 * center - i;
            if (i < radius){
                palindromeRadii[i] = min(radius - i, palindromeRadii[mirror]);
            }
            
            while ((i + 1 + palindromeRadii[i] < n) && (i - 1 - palindromeRadii[i] >= 0) && sPrime[i + 1 + palindromeRadii[i]]\
                   == sPrime[i - 1 - palindromeRadii[i]]){
                ++palindromeRadii[i];
            }
            
            if (i + palindromeRadii[i] > radius){
                center = i;
                radius = i + palindromeRadii[i];
            }
        }
        
        int maxLength = 0, centerIndex = 0;
        for (int i = 0; i < n; ++i){
            if (maxLength < palindromeRadii[i]){
                maxLength = palindromeRadii[i];
                centerIndex = i;
            }
        }
        int startIndex = (centerIndex - maxLength) >> 1;
        return s.substr(startIndex, maxLength);
    }
};