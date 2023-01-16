class Solution {
private:
    int LEFT_BOUND, RIGHT_BOUND;
    string s, t;
public:
    bool rec_isSubsequence(int left_index, int right_index){
        if (this -> LEFT_BOUND == left_index) return true;
        if (this -> RIGHT_BOUND == right_index) return false;
        if (this -> s[left_index] == this -> t[right_index]) ++left_index;
        ++right_index;
        return rec_isSubsequence(left_index, right_index);
    }
    
    bool isSubsequence(string s, string t) {
        this -> LEFT_BOUND = s.size(), this -> RIGHT_BOUND = t.size();
        this -> s = s, this -> t = t;
        return rec_isSubsequence(0, 0);
    }
};