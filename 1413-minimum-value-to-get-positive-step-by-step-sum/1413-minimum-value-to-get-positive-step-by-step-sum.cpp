class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int start_value = 1;
        while (true){
            int total = start_value;
            bool is_valid = true;
            
            for (const int& num: nums) {
                total += num;
                if (total < 1) {is_valid = false; break;}
            }
            
            if (is_valid) return start_value;
            else ++start_value;
        }
    }
};