class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = *max_element(arr.begin(), arr.end()), curr = arr[0], winstreak = 0, opponent;
        queue<int> queue({arr.begin() + 1, arr.end()});
        
        while (!queue.empty()){
            opponent = queue.front();
            queue.pop();
            
            if (curr > opponent){
                queue.push(opponent);
                ++winstreak;
            }
            else{
                queue.push(curr);
                curr = opponent;
                winstreak = 1;
            }
            
            if (curr == mx || winstreak == k)
                return curr;
        }
        
        return -1;
    }
};