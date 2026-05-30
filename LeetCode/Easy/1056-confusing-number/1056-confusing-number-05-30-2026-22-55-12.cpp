class Solution {
public:
    bool confusingNumber(int n) {
        string num = to_string(n);
        unordered_map<char, char> rotated {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        unordered_set<char> invalid{'2', '3', '4', '5', '7'};
        string rNum = num;

        for (int i = 0; i < num.size(); ++i) {
            if (invalid.contains(num[i])) return false;
            rNum[i] = rotated[num[i]];
        }

        reverse(rNum.begin(), rNum.end());
        return rNum != num;
    }
};