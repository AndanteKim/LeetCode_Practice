class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> pq;
        unordered_map<char, int> m;
        string ans = "";
        for (char& c : s) ++m[c];
        for (auto& [key, val] : m) pq.push({key, val});
        
        while (!pq.empty()){
            auto [key, val] = pq.top();
            pq.pop();
            if (!ans.empty() && ans.back() == key){
                if (pq.empty()) break;
                auto[nextKey, nextVal] = pq.top();
                pq.pop();
                ans += nextKey;
                --nextVal;
                if (nextVal > 0) pq.push({nextKey, nextVal});
                pq.push({key, val});
            }
            else{
                int m = min(val, repeatLimit);
                for (int i = 0; i < m; ++i) ans += key;
                if (val - m > 0) pq.push({key, val - m});
            }
        }
        return ans;
    }
};