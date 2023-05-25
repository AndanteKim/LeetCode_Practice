class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int p_i = 0, t_i = 0, ans = 0;
        
        while (p_i < players.size() && t_i < trainers.size()){
            if (players[p_i] <= trainers[t_i]){
                ++p_i;
                ++t_i;
                ++ans;
            }
            else ++t_i;
        }
        
        return ans;
    }
};