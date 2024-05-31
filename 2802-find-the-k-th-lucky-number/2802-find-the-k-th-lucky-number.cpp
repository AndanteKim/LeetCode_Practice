class Solution {
public:
    string kthLuckyNumber(int k) {
        // c := the number of digits
        // numCount := the number of lucky numbers with c or fewer digits
        int c = 0, numCount = 0;
        
        while (numCount < k){
            ++c;
            numCount += (1 << c);
        }
        
        // Calculate the number of lucky numbers with c digits before the kth
        // lucky number
        int x = k - 1 - (numCount - (1 << c));
        
        // Build result using x by pretending 0 for 4 or 1 for 7
        string kthLuckyNumber = "";
        for (int i = 0; i < c; ++i){
            if (x % 2 == 1)
                kthLuckyNumber.insert(0, "7");
            else
                kthLuckyNumber.insert(0, "4");
            x >>= 1;
        }
        
        return kthLuckyNumber;
    }
};