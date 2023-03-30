class Solution {
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[node] = true;
        for (int room : rooms[node]){
            if(!visited[room]) dfs(room, rooms, visited);
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(0, rooms, visited);
        
        return count(visited.begin(), visited.end(), false) == 0;
    }
};