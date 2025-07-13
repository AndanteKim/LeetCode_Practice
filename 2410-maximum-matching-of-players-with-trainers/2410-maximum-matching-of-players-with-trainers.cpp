class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int m = players.size(), n = trainers.size(), ans = 0;
        int i = 0, j = i; 
        while (i < m && j < n){
            while (j < n && players[i] > trainers[j])
                ++j;

            if (j < n) ++ans;

            ++i;
            ++j;
        }
        
        return ans;
    }
};