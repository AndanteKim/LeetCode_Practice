class Solution {
public:
    int addDigits(int num) {
        while (num >= 10){
            int curr = 0;
            while (num > 0){
                curr += num % 10;
                num /= 10;
            }
            num = curr;
        }
        
        return num;
    }
};