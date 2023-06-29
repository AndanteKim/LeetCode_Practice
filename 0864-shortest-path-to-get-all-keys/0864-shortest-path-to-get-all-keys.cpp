class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, set<pair<int, int>>> seen;
        unordered_set<char> keySet, lockSet;
        int allKeys = 0, startR = -1, startC = -1;
        string lowerCases = "abcdef", upperCases = "ABCDEF";
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                char cell = grid[i][j];
                if (lowerCases.find(cell) != string::npos){
                    allKeys += (1 << (int)(cell - 'a'));
                    keySet.insert(cell);
                }
                if (upperCases.find(cell) != string::npos){
                    lockSet.insert(cell);
                }
                if (cell == '@'){
                    startR = i, startC = j;
                }
            }
        }
        queue<vector<int>> queue;
        queue.push({startR, startC, 0, 0});
        seen[0].insert({startR, startC});
        
        while (!queue.empty()){
            auto it = queue.front();
            queue.pop();
            int row = it[0], col = it[1], keys = it[2], dist = it[3];
            
            for (auto& [newR, newC] : vector<pair<int, int>>{make_pair(row + 1, col), make_pair(row - 1, col), make_pair(row, col + 1), make_pair(row, col - 1)}){
                if (newR < 0 || newR >= m || newC < 0 || newC >= n || grid[newR][newC] == '#') continue;
                int cell = grid[newR][newC];
                
                if (keySet.find(cell) != keySet.end() && (!(keys & (1 << (int)(cell - 'a'))))){
                    int newKeys = (keys | 1 << (int)(cell - 'a'));
                    if (newKeys == allKeys) return dist + 1;
                    seen[newKeys].insert({newR, newC});
                    queue.push({newR, newC, newKeys, dist + 1});
                }
                else if (lockSet.find(cell) != lockSet.end() && (!(keys & (1 << (int)(cell - 'A'))))) continue;
                else if (seen[keys].find({newR, newC}) == seen[keys].end()){
                    seen[keys].insert({newR, newC});
                    queue.push({newR, newC, keys, dist + 1});
                }
            }
            
        }
        
        return -1;
    }
};