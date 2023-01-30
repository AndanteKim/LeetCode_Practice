class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> group_list;
        vector<int> curr_chars;
        vector<vector<string>> answer;
        for (const string& str: strs){
            curr_chars.assign(26, 0);
            for (const char& c : str){
                ++curr_chars[c - 'a'];
            }
            group_list[curr_chars].push_back(str);
            
        }
        
        for (const auto&[key, value] : group_list){
            answer.push_back(value);
        }
        return answer;
    }
};