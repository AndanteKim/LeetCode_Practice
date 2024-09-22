class Solution {
private:
    // To count how many numbers exist between prefix1 and prefix2 
    int countSteps(int n, long prefix1, long prefix2){
        int steps = 0;
        
        while (prefix1 <= n){
            steps += min((long)n + 1, prefix2) - prefix1;
            
            prefix1 *= 10;
            prefix2 *= 10;
        }
        
        return steps;
    }
    
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        --k;
        
        while (k > 0){
            int steps = countSteps(n, curr, curr + 1);
            
            // If the steps are less than or equal to k, we skip this prefix's subtree
            if (steps <= k){
                // Move to the next prefix and decrease k by the number of steps we skip
                ++curr;
                k -= steps;
            }
            else{
                // Move to the next level of the tree and decrement k by 1
                curr *= 10;
                --k;
            }
        }
        
        return curr;
    }
};