class Solution {
public:
    int findComplement(int num) {
        int todo = num, flip = 1;
        
        while (todo){
            // flip the current bit
            num ^= flip;
            
            // prepare for the next run
            flip <<= 1;
            todo >>= 1;
        }
        
        return num;
    }
};