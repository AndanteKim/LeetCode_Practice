class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> letter_indices_table;
        for (int i = 0; i < t.size(); ++i) letter_indices_table[t[i]].push_back(i);
        
        int cur_match_index = -1, match_index;
        vector<int> indices_list;
        for (const auto &letter:s){
            if (letter_indices_table.find(letter) == letter_indices_table.end()) return false;
            indices_list = letter_indices_table[letter];
            match_index = upper_bound(indices_list.begin(), indices_list.end(), cur_match_index) - indices_list.begin();
            if (match_index != indices_list.size()) cur_match_index = indices_list[match_index];
            else return false;
        }
        return true;
    }
};