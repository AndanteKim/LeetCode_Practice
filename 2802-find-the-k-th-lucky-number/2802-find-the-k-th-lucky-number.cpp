class Solution {
public:
    string kthLuckyNumber(int k) {
        // Increment k to account for 1-based indexing
        k = k + 1;
        
        int digits = log2(k);
        
        // Place '4' for '0' and '1' for '7'
        string kthLuckyNum(digits, ' ');
        while (k > 1){
            --digits;
            kthLuckyNum[digits] = ((k & 1)? '7' : '4');
            k >>= 1;
        }
        
        return kthLuckyNum;
    }
};