class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0, start = 2, push = 1;
        priority_queue<int, vector<int>> pq;
        unordered_map<char, int> count;
        
        for (char& c : word)
            ++count[c];
        
        for (auto& [_, val] : count)
            pq.push(val);
        
        while (!pq.empty()){
            ans += pq.top() * push;
            pq.pop();
            ++start;
            if (start > 9){
                start = 2;
                ++push;
            }
        }
        
        return ans;
    }
};