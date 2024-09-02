class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Find the sum of all elements
        long sum = 0;
        
        for (int i = 0; i < chalk.size(); ++i){
            sum += chalk[i];
            if (sum > k)
                break;
        }
        // Find the modulo k with sum.
        k %= sum;
        
        for (int i = 0; i < chalk.size(); ++i){
            if (k < chalk[i])
                return i;
            
            k -= chalk[i];
        }
        
        return 0;
    }
};