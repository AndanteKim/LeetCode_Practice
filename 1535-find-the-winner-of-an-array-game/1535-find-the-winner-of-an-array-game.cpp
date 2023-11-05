class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = *max_element(arr.begin(), arr.end()), curr = arr[0], winstreak = 0, opponent;
        
        for (int i = 1; i < arr.size(); ++i){
            opponent = arr[i];
            if (curr > opponent){
                ++winstreak;
            }
            else{
                curr = opponent;
                winstreak = 1;
            }
            
            if (curr == mx || winstreak == k)
                return curr;
        }
        
        return -1;
    }
};