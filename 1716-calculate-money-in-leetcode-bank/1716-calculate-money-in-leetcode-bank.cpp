class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7, F = 28, L = F + (k - 1) * 7;
        int arithmeticSum = (k * (F + L)) >> 1, monday = 1 + k, finalWeek = 0;
        
        for (int day = 0; day < n % 7; ++day)
            finalWeek += monday + day;
        return arithmeticSum + finalWeek;
    }
};