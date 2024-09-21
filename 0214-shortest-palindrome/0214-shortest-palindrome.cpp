typedef long long ll;

class Solution {
public:
    string shortestPalindrome(string s) {
        ll n = s.size(), mod = 1e9 + 7, hashBase = 29;
        ll forwardHash = 0, reversedHash = 0, power = 1;
        int palindromeEndIndex = -1;
        
        // Calculate the rolling hashes and find the longest palindromic prefix
        for (int i = 0; i < n; ++i){
            // Update the forward hash
            forwardHash = (forwardHash * hashBase + (s[i] - 'a' + 1)) % mod;
            
            // Update the reverse hash
            reversedHash = (reversedHash + (s[i] - 'a' + 1) * power) % mod;
            power = (power * hashBase) % mod;
            
            // If forward and reverse hashes match, update palindrome end index
            if (forwardHash == reversedHash) palindromeEndIndex = i;
        }
        
        // Find the remaining suffix after the longest palindromic prefix
        string suffix = s.substr(palindromeEndIndex + 1);
        
        // Reverse the remaining suffix
        string reversedSuffix(suffix.rbegin(), suffix.rend());
        
        // Prepend the reversed suffix to the original string and return the result
        return reversedSuffix + s;
    }
};