class Solution {
public:
    int minDeletions(string s) {
        // store the frequency of each character
        vector<int> chars(26);
        for (char& c : s) ++chars[c - 'a'];
        
        // add the frequencies to priority queue
        int ans = 0;
        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) if (chars[i]) pq.push(chars[i]);
        
        while (pq.size() > 1){
            int topElement = pq.top();
            pq.pop();
            
            // If the top two elements in the priority queue are the same
            if (topElement == pq.top()){
                // decrement the popped value and push it back into the queue
                if (topElement - 1 > 0) {
                    pq.push(topElement - 1);
                }
                ++ans;
            }
        }
        
        return ans;
    }
};