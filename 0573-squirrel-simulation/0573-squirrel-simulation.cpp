class Solution {
private:
    int distance(int x, int y, vector<int>& target){
        return abs(x - target[0]) + abs(y - target[1]);
    }
    
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int totalDist = 0, squirrelToClosest = INT_MAX;
        
        for (vector<int>& nut : nuts){
            totalDist += 2 * distance(nut[0], nut[1], tree);
            // find the shortest distance between the a squirrel and nut with deducting a distance between the tree and nut.
            squirrelToClosest = min(squirrelToClosest, -distance(nut[0], nut[1], tree) + distance(nut[0], nut[1], squirrel));
        }
        
        return totalDist + squirrelToClosest;
    }
};