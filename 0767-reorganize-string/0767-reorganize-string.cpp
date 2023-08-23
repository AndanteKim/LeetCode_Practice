class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        unordered_map<char, int> m;
        for (char& c : s) ++m[c];
        
        for (auto& [key, cnt] : m) pq.push(make_pair(cnt, key));
            
        while (!pq.empty()){
            auto [cntFirst, charFirst] = pq.top();
            pq.pop();
            
            if (ans.empty() || charFirst != ans.back()){
                ans.push_back(charFirst);
                if (cntFirst > 1) pq.push(make_pair(cntFirst - 1, charFirst));
            }
            else{
                if (pq.empty()) return "";
                auto [cntSecond, charSecond] = pq.top();
                pq.pop();
                ans.push_back(charSecond);
                if (cntSecond > 1) pq.push(make_pair(cntSecond - 1, charSecond));
                pq.push(make_pair(cntFirst, charFirst));
            }
        }
        
        return ans;
    }
};