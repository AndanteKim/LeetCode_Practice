class Solution {
public:
    long long minimumSteps(string s) {
        int whitePosition = 0;
        long long ans = 0;
        
        // Iterate through each ball in the string
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '0'){
                // Calculate the number of swaps needed
                // Move to the next available position for a white ball one step to the right
                ans += i - whitePosition++;
            }
        }
        
        return ans;
    }
};