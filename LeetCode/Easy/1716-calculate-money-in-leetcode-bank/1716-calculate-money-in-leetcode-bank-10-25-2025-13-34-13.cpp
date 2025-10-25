class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7;
        int F = 28, L = 28 + (k - 1) * 7;
        int arithmeticSum = (k * (F + L)) >> 1;
        int monday = k + 1, finalWeek = 0;

        for (int day = 0; day < n % 7; ++day) finalWeek += monday + day;  

        return arithmeticSum + finalWeek;
    }
};