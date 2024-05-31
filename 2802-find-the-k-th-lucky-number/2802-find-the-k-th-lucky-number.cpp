class Solution {
public:
    string kthLuckyNumber(int k) {
        // Increment k to account for 1-based indexing
        ++k;
        
        // For each digit in the binary representation of k except the most
        // significant pretend 4 to the result if the digit is 0 and 7 otherwise
        string kthLuckyNumber = "";
        while (k > 1){
            kthLuckyNumber.insert(0, ((k & 1)? "7":"4"));
            k >>= 1;
        }
        
        return kthLuckyNumber;
    }
};