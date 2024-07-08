class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(i);
        
        int count = 1;
        while (q.size() > 1){
            int curr = q.front(); q.pop();
            
            if (count == k){
                count = 1;
            }
            else{
                ++count;
                q.push(curr);
            }
        }
        
        return q.front();
    }
};