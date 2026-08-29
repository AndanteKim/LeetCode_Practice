class Solution {
private:
    string findTarget(string section) {
        int num = stoi(section, nullptr, 16);
        int x = round(num * 1.0 / 17);
    
        char ans = (x > 9? 'a' + x - 10 : '0' + x);
        return string(2, ans);
    } 

public:
    string similarRGB(string color) {
        string ans = "#";
        for (int i = 1; i < 6; i += 2) ans += findTarget(color.substr(i, 2));
        return ans;
    }
};