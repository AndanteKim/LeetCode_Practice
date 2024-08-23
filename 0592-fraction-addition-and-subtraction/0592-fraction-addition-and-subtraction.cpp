class Solution {
private:
    int findGCD(int a, int b){
        if (a == 0)
            return b;
        
        return findGCD(b % a, a);
    }
    
public:
    string fractionAddition(string expression) {
        int num = 0, denom = 1;
        int i = 0, n = expression.size();
        
        while (i < n){
            int currNum = 0, currDenom = 0;
            bool isNegative = false;
            
            // Check for sign
            if (expression[i] == '-' || expression[i] == '+'){
                if (expression[i] == '-') isNegative = true;
                // Move to next character
                ++i;
            }
            
            // Build numerator
            while (i < n && isdigit(expression[i])){
                int val = expression[i] - 48;
                currNum = currNum * 10 + val;
                ++i;
            }
            
            if (isNegative) currNum *= -1;
            
            // Skip the divisor
            ++i;
            
            // Build denominator
            while (i < n && isdigit(expression[i])){
                int val = expression[i] - 48;
                currDenom = currDenom * 10 + val;
                ++i;
            }
            
            // Add fractions together using common denominator
            num = num * currDenom + currNum * denom;
            denom *= currDenom;
        }
        
        int gcd = abs(findGCD(num, denom));
        
        // Reduce fractions
        num /= gcd;
        denom /= gcd;
        
        return to_string(num) + "/" + to_string(denom);
    }
};