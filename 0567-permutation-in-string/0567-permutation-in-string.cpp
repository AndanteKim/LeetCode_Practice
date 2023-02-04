class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<char> sort_s1(s1.begin(), s1.end());
        sort(sort_s1.begin(), sort_s1.end());
        
        vector<char> sort_s2(s2.begin(), s2.end());
        
        int l1 = s1.size(), l2 = s2.size();
        for (int i = 0; i <= l2 - l1; ++i){
            vector<char> sub_vec(sort_s2.begin() + i, sort_s2.begin() + i + l1);
            sort(sub_vec.begin(), sub_vec.end());
            if (sort_s1 == sub_vec) return true;
        }
        return false;
    }
};