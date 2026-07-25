class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;

        while (n > 0) {
            int d = n % 10;

            if (d > first) {
                int temp = first;
                first = d;
                second = temp;
            }
            else if (d > second) second = d;

            n /= 10;
        }

        return first * second;
    }
};