class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Concise simulation
        int five = 0, ten = 0;
        
        for (int bill : bills){
            if (bill == 5)
                ++five;
            else if (bill == 10){
                --five;
                ++ten;
            }
            else if (ten > 0){
                --five;
                --ten;
            }
            else five -= 3;
            
            if (five < 0)
                return false;
        }
        
        return true;
    }
};