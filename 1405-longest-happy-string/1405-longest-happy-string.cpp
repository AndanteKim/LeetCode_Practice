class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        
        // Add the counts of a, b, and c in priority queue.
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string ans = "";
        while (!pq.empty()){
            auto [count, ch] = pq.top(); pq.pop();
            
            // If three consecutive characters exist, pick the second most frequent character.
            if (ans.size() >= 2 && ans[ans.size() - 1] == ch && ans[ans.size() - 2] == ch){
                if (pq.empty()) break;
                auto [tempCount, tempCh] = pq.top(); pq.pop();
                
                ans.push_back(tempCh);
                if (tempCount > 1) pq.push({tempCount - 1, tempCh});
                pq.push({count, ch});
            }
            else{
                ans.push_back(ch);
                if (count > 1)
                    pq.push({count - 1, ch});
            }
        }
        
        return ans;
    }
};