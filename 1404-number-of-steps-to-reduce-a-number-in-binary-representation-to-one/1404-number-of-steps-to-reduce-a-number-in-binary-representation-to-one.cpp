class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), operations = 0, carry = 0;
        
        for (int i = n - 1; i > 0; --i){
            int digit = (s[i] - 48) + carry; 
            
            if (digit % 2 == 1){
                operations += 2;
                carry = 1;
            }
            else
                ++operations;
        }
        
        return operations + carry;
    }
};