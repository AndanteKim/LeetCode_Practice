class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> p;
        
        for (int i = 0; i < names.size(); ++i){
            p.push_back({names[i], heights[i]});
        }
        
        sort(p.begin(), p.end(), [](pair<string, int>& a, pair<string, int>& b){return a.second > b.second;});
        
        vector<string> ans;
        
        for (int i = 0; i < p.size(); ++i)
            ans.push_back(p[i].first);
        
        return ans;
    }
};