class Solution {
public:
    void helper(int i, int j, vector<char>& s){
        if (i >= j) return;
        if (i < j) swap(s[i], s[j]);
        helper(i + 1, j - 1, s);
    }
    
    void reverseString(vector<char>& s) {
        helper(0, s.size()-1, s);
    }
};