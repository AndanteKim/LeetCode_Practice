class Solution {
private:
    int removeSubstr(string& s, string target, int ptPerRemoval){
        int writeIdx = 0, total = 0;
        
        // Iterate through the string
        for (int readIdx = 0; readIdx < s.size(); ++readIdx){
            // Add the current character
            s[writeIdx++] = s[readIdx];
            
            // Check if we've written at least two characters and
            // they match the target substring
            if (writeIdx > 1 && s[writeIdx - 2] == target[0] &&\
               s[writeIdx - 1] == target[1]){
                writeIdx -= 2; // Move write index back to remove the match
                total += ptPerRemoval;
            }
        }
        
        // Trim the string to remove any leftover characters
        s.erase(s.begin() + writeIdx, s.end());
        
        return total;
    }
        
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        
        if (x > y){
            // Remove "ab" first (higher points), then "ba" 
            ans += removeSubstr(s, "ab", x);
            ans += removeSubstr(s, "ba", y);
        }
        else{
            // Remove "ba" first (higher or equal points), then "ab"
            ans += removeSubstr(s, "ba", y);
            ans += removeSubstr(s, "ab", x);
        }
        
        return ans;
    }
};