class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto waviness = [](int n) -> int {
            string num = to_string(n);
            int count = 0;
            for (int i = 1; i < num.size() - 1; ++i) {
                bool isPeak = (num[i - 1] < num[i] && num[i] > num[i + 1]);
                bool isValley = (num[i - 1] > num[i] && num[i] < num[i + 1]);

                if (isPeak || isValley) ++count;
            }

            return count;
        };
        
        int ans = 0;

        for (int num = num1; num <= num2; ++num) {
            ans += waviness(num);
        }

        return ans;
    }
};