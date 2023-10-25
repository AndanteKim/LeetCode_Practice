class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        
        // We assume the symbol at the target position is '1'
        int symbol = 1;
        
        for (int currRow = n; currRow > 1; --currRow){
            int totalElements = 1 << (currRow - 1);
            int halfElements = totalElements / 2;
            
            // If 'k' lies in the right half symbol, then we flip over to the respective left half symbol
            if (k > halfElements){
                // Flip the symbol
                k -= halfElements;
                
                // Change the position after flipping
                symbol = 1 - symbol;
            }
        }
        
        // We reached the 1st row; if the symbol is not '0', we started with the wrong symbol
        if (symbol != 0)
            // Thus, the start symbol was '0', not '1'
            return 0;
            
        // The start symbol was indeed what we started with a '1'
        return 1;
    }
};