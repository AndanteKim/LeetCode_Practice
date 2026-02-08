class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), minDeletions = 0, bCnt = 0;

        for (const char& c : s) {
            if (c == 'b') {
                ++bCnt;
            }
            else {
                minDeletions = min(minDeletions + 1, bCnt);
            }
        }

        return minDeletions;
    }
};