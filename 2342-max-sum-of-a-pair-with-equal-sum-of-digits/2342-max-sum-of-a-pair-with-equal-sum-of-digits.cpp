class Solution {
public:
    int get_digit_sum(int num){
        int digit_sum = 0;
        while (num > 0){
            digit_sum += num % 10;
            num /= 10;
        }
        return digit_sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> dic;
        int ans = -1, digit_sum;
        for (const int &num : nums){
            digit_sum = get_digit_sum(num);
            if (dic.find(digit_sum) != dic.end()) ans = max(ans, num + dic[digit_sum]);
            dic[digit_sum] = max(dic[digit_sum], num);
        }
        return ans;
    }
};