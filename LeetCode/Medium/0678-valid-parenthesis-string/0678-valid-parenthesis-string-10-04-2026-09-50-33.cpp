class Solution {
public:
    bool checkValidString(string s) {
        int length = s.size() - 1, openCnt = 0, closeCnt = 0;

        for (int i = 0; i < length + 1; ++i) {
            if (s[i] == '(' || s[i] == '*') ++openCnt;
            else --openCnt;

            if (s[length - i] == ')' || s[length - i] == '*') ++closeCnt;
            else --closeCnt;

            if (openCnt < 0 || closeCnt < 0) return false;
        }

        return true;
    }
};