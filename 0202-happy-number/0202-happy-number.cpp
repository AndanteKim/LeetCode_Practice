class Solution {
public:
    int get_next(int number){
        int total_sum = 0, digit;
        while (number > 0){
            
            digit = number % 10;
            number /= 10;
            total_sum += pow(digit, 2);
        }
        return total_sum;
    }
    
    bool isHappy(int n) {
        int slow_runner = n, fast_runner = get_next(n);
        
        while(fast_runner != 1 && slow_runner != fast_runner){
            slow_runner = get_next(slow_runner);
            fast_runner = get_next(get_next(fast_runner));
        }
        
        return fast_runner == 1;
    }
};