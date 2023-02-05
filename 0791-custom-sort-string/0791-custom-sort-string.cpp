class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> count_s;
        set<char> s_list, o_list;
        string ans = "";
        for (const char &c: s){ 
            ++count_s[c];
            s_list.insert(c);
        }
        
        for (const char &c : order) {
            o_list.insert(c);
            while (count_s[c] > 0) {
                ans += c;
                --count_s[c];
            }
        }
        set<char> diff;
        set_difference(s_list.begin(), s_list.end(), o_list.begin(), o_list.end(), inserter(diff, diff.end()));
        
        for (const char &c: diff){
            while (count_s[c] > 0){
                ans += c;
                --count_s[c];
            }
        }
        
        return ans;
    }
};