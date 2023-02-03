class Solution {
public:
    string frequencySort(string s) {
        string ans;
        int freq[256]{0};
        priority_queue<pair<int, char>>pq;
        for (const char&c:s) ++freq[c];
        for (int i = 0; i < 256; ++i) if (freq[i]) pq.push(make_pair(freq[i], i));
        
        while (!pq.empty()){
            ans.append(pq.top().first, pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};