class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0, n1 = num1, n2 = num2;

        while (n1 > 0 and n2 > 0) {
            ans += n1 / n2;
            n1 %= n2;
            swap(n1, n2);
        }

        return ans;
    }
};