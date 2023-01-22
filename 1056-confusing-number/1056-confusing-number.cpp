class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<char, char> invert_map({{'0','0'}, {'1','1'},{'6','9'},{'8','8'},{'9','6'}});
        string rev_n = "";
        for (const auto &ch: to_string(n)){
            if (invert_map.find(ch) == invert_map.end()) return false;
            rev_n += invert_map[ch];
        }
        reverse(rev_n.begin(), rev_n.end());
        
        return stoi(rev_n) != n;
    }
};