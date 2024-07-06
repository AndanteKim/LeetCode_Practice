class Solution {
public:
    int passThePillow(int n, int time) {
        int curr = 1, sign = 1;
        
        while (time-- > 0){
            curr += sign;
            
            if (curr == 1 || curr == n)
                sign *= -1;
            
        }
        
        return curr;
    }
};