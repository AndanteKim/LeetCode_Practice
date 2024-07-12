class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Ensure that "ab" always has more points than "ba".
        if (x < y){
            // Reverse the string to maintain logic
            reverse(s.begin(), s.end());
            
            // Swap points
            swap(x, y);
        }
        
        int ans = 0, aCount = 0, bCount = 0;
        
        for (char& c : s){
            if (c == 'a'){
                ++aCount;
            }
            else if (c == 'b'){
                if (aCount > 0){
                    // Can form "ab", remove it and add points
                    --aCount;
                    ans += x;
                }
                else
                    // Can't form "ab", keep "b" for potential future "ba"
                    ++bCount;
            }
            else{
                // Non 'a' or 'b' character encountered
                // Calculate points for any remaining "ba" pairs
                ans += min(aCount, bCount) * y;
                
                // Reset counters for the next segment
                aCount = 0; bCount = 0;
            }
        }
        
        // Calculate points for any remaining "ba" pairs at the end
        ans += min(aCount, bCount) * y;
        
        return ans;
    }
};