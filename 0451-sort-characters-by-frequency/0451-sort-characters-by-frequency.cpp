class Solution {
    
    
public:
    static bool sortByVal(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        map<char, int> dict_s;
        string answer = "";
        
        for (const char& c : s) ++dict_s[c];
        
        vector<pair<char, int>> vec;
        map<char, int>::iterator it;
        for (it = dict_s.begin(); it != dict_s.end(); ++it)
            vec.push_back(make_pair(it -> first, it -> second));
        sort(vec.begin(), vec.end(), sortByVal);
        for (int i = 0; i < vec.size(); ++i)
            for (int j = 0; j < vec[i].second; ++j) answer += vec[i].first;
        
        return answer;
    }
};