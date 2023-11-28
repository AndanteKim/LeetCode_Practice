class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1'000'000'007, n = corridor.size();
        int seats = 0, prevPairLast = -1;
        long count = 1;
        
        for (int i = 0; i < n; ++i){
            if (corridor[i] == 'S'){
                ++seats;
                if (seats == 2){
                    seats = 0;
                    prevPairLast = i;
                }
                else if (seats == 1 && prevPairLast != -1){
                    count = (count * (i - prevPairLast)) % MOD;
                }
            }
        }
        
        // If odd seats, or zero seats
        if (seats == 1 || prevPairLast == -1)
            return 0;
        return (int)count;
    }
};