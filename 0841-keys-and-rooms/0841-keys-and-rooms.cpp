class Solution {
private:
    void dfs(int start, vector<bool>& visited, vector<vector<int>>& rooms){
        if (!visited[start]){
            visited[start] = true;
            for (int neighbor : rooms[start])
                dfs(neighbor, visited, rooms);
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);
        dfs(0, visited, rooms);
        return count(visited.begin(), visited.end(), true) == n;
    }
};