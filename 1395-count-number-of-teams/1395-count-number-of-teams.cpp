class Solution {
public:
    int numTeams(vector<int>& rating) {
        // Bottom Up(tabulation)
        int n = rating.size(), teams = 0;
        
        // Tables for increasing and decreasing sequences
        vector<vector<int>> increasingTeams(n, vector<int>(4)), decreasingTeams(n, vector<int>(4));
        
        // Fill the base cases. (Each soldier is a sequence of length 1)
        for (int i = 0; i < n; ++i){
            increasingTeams[i][1] = 1;
            decreasingTeams[i][1] = 1;
        }
        
        // Fill the tables
        for (int count = 2; count < 4; ++count){
            for (int i = 0; i < n; ++i){
                for (int j = i + 1; j < n; ++j){
                    // Increasing
                    if (rating[i] < rating[j])
                        increasingTeams[j][count] += increasingTeams[i][count - 1];
                    
                    // Decreasing
                    if (rating[i] > rating[j])
                        decreasingTeams[j][count] += decreasingTeams[i][count - 1];
                }
            }
        }
        
        // Sum up the result (All sequences of length 3)
        for (int i = 0; i < n; ++i){
            teams += increasingTeams[i][3] + decreasingTeams[i][3];
        }
        
        return teams;
    }
};