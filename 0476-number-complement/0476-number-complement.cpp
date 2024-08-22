class Solution {
public:
    int findComplement(int num) {
        int n = log2(num);
        return (long)(1 << (n + 1)) - 1 - num;
    }
};