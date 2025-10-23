class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        string newS = s, reduced;

        while (n > 2){
            reduced = "";
            for (int i = 0; i < n - 1; ++i){
                reduced.push_back(((newS[i] - '0') + (newS[i + 1] - '0')) % 10 + '0');
            }
            newS = reduced;
            n = reduced.size();
        }

        return newS[0] == newS[1];
    }
};