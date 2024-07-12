class Solution {
private:
    string removeSubstr(string& input, string& target){
        string stack = "";
        
        // Iterate through each character in the input string
        for (char& c : input){
            // Check if current character forms the target pair with the top of
            // the stack
            if (c == target.back() && !stack.empty() && stack.back() == target[0])
                stack.pop_back(); // Remove the matching character from the stack
            else
                stack.push_back(c);
        }
        return stack;
    }
    
public:
    int maximumGain(string s, int x, int y) {
        string highPriorityPair = (x > y)? "ab" : "ba";
        string lowPriorityPair = (highPriorityPair == "ab")? "ba" : "ab";
        int ans = 0;
        
        // First pass: remove the high priority pair
        string StrAfterFirstPass = removeSubstr(s, highPriorityPair);
        
        // Calculate score from the first pass
        int removedPairsCount = (s.size() - StrAfterFirstPass.size()) >> 1;
        ans += removedPairsCount * max(x, y);
        
        // Second pass: remove the low priority pair
        string StrAfterSecondPass = removeSubstr(StrAfterFirstPass, lowPriorityPair);
        removedPairsCount = (StrAfterFirstPass.size() - StrAfterSecondPass.size()) >> 1;
        
        // Calculate score from second pass
        ans += removedPairsCount * min(x, y);
        
        return ans;
    }
};