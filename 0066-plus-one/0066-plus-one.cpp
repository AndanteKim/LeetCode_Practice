class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // In-place
        int carry = 1;
        
        // Move along the input array starting from the end
        for (int i = digits.size() - 1; i >= 0; --i){
            int temp = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = temp;
        }
        
        // If carry is larger than 0, then insert 1 at the digits' begin
        if (carry)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};