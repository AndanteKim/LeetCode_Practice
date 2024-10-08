class Solution {
public:
    int minSwaps(string s) {
        // Space-optimized stack
        int stackSize = 0;
        
        for (const auto& c : s){
            // If the character is opening bracket, then increment the stack size.
            if (c == '[')
                ++stackSize;
            else{
                // If the character is closing bracket and we have an opening bracket, decrement
                // the stack size.
                if (stackSize > 0) --stackSize;
            }
        }
        
        return (stackSize + 1) >> 1;
    }
};