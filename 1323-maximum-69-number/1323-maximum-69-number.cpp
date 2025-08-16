class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        int n = num;

        while (n > 0){
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());
        int digit = digits.size() - 1, ans = 0;
        bool changeable = true;

        for (int d : digits){
            if (changeable && d != 9){
                changeable = false;
                ans += 9 * pow(10, digit--);
            }
            else
                ans += d * pow(10, digit--);
        }

        return ans;
    }
};