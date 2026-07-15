class Solution {
private:
    int gcd(int n1, int n2) {
        if (n1 < n2) swap(n1, n2);

        while (n2 != 0) {
            int temp = n1 % n2;
            n1 = n2;
            n2 = temp;
        }

        return n1;
    }

public:
    int gcdOfOddEvenSums(int n) {
        int odd = n * n, even = n * n + n;
        return gcd(odd, even);
    }
};