class Solution {
private:
    void rec(int i, int j, vector<char>& s){
        if (i > j) return;

        swap(s[i++], s[j--]);
        rec(i, j, s);
    }

public:
    void reverseString(vector<char>& s) {
        rec(0, s.size() - 1, s);
    }
};