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
        set<int> seen;
        
        while (n != 1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n = get_next(n);
        }
            
        return n == 1;
    }
};