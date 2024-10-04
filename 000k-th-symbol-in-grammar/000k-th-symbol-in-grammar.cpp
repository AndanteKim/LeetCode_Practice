class Solution {
private:
    int recursion(int remain, int position){
        // Base case: First row will only have one symbol '0'.
        if (remain == 1) return 0;
        
        int totalNodes = 1 << (remain - 1);
        int halfNodes = totalNodes >> 1;
        
        // If the target is present in the right half, we switch to the respective left half symbol.
        if (position > halfNodes)
            return 1 - recursion(remain, position - halfNodes);
        
        // Otherwise, we switch to the previous one.
        return recursion(remain - 1, position);
    }
    
public:
    int kthGrammar(int n, int k) {
        return recursion(n, k);
    }
};