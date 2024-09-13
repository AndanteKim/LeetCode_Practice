class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // In-place
        int carry = 1;
        
        for (int i = digits.size() - 1; i >= 0; --i){
            int temp = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = temp;
        }
        
        if (carry)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};