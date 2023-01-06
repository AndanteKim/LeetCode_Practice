class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x_incre = coordinates[1][0] - coordinates[0][0], y_incre = coordinates[1][1] - coordinates[0][1];
        
        for (int i = 2; i < coordinates.size(); ++i){
            if (x_incre * (coordinates[i][1] - coordinates[i-1][1]) != y_incre * (coordinates[i][0] - coordinates[i-1][0])) return false;
        }
        
        return true;
    }
};