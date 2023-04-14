class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> queue{{start}};
        int n = arr.size();
        int end = n - 1;
        vector<bool> visited(n);
        
        while (!queue.empty()){
            int index = queue.front();
            queue.pop();
            if (arr[index] == 0) return true;
            
            int neg_jump = index - arr[index], pos_jump = index + arr[index];
            
            if (neg_jump >= 0 && neg_jump <= end && !visited[neg_jump]){
                visited[neg_jump] = true;
                queue.push(neg_jump);
            }
            
            if (pos_jump >= 0 && pos_jump <= end && !visited[pos_jump]){
                visited[pos_jump] = true;
                queue.push(pos_jump);
            }
        }
        
        return false;
    }
};