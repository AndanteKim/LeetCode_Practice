class Solution {
public:
    bool sumGame(string num) {
        int sumL = 0, sumR = 0, qL = 0, qR = 0;
        int n = num.size();

        for (int i = 0; i < n; ++i) {
            if (i < (n >> 1)) {
                if (num[i] == '?') ++qL;
                else sumL += (num[i] - 48);
            }
            else {
                if (num[i] == '?') ++qR;
                else sumR += (num[i] - 48);
            }
        }

        if ((qL + qR) % 2) return true;

        int ds = sumL - sumR, dq = qR - qL;
        return ds != (dq >> 1) * 9;
    }
};