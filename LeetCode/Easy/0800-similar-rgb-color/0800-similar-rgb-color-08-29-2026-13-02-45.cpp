class Solution {
private:
    string findTarget(string section) {
        int num = stoi(section, nullptr, 16);

        int ans = -1, minDiff = 1000;

        for (int i = 0; i < 16; ++i) {
            int currDiff = (i * 17 - num) * (i * 17 - num);
            if (currDiff < minDiff) {
                minDiff = currDiff;
                ans = i;
            }
        }

        string ansHex{char(ans > 9? 'a' + ans - 10 : '0' + ans)};
        return ansHex + ansHex;
    }

public:
    string similarRGB(string color) {
        string ans = "#";
        for (int i = 1; i < 6; i += 2) ans += findTarget(color.substr(i, 2));
        return ans;
    }
};