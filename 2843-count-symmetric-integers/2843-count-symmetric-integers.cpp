class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for (int num = low; num <= high; ++num){
            string curr = to_string(num);
            int n = curr.size(), j = n >> 1;
            if (n % 2) continue;
            int first = 0, second = 0;
            for (int i = 0; i < n >> 1; ++i){
                first += curr[i] - '0';
                second += curr[i + j] - '0';
            }

            if (first == second) ++ans;
        }

        return ans;
    }
};