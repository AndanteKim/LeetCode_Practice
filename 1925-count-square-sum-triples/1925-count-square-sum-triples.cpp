class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                double sum = sqrt(i * i + j * j);
                if ((int)sum == sum && sum <= n) ++ans;
            }
        }

        return ans;
    }
};