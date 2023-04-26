#define ll long long

class Solution {
    bool isOverlapped(int sX, int sY, int sR, int nX, int nY){
        return ((ll)abs(nX - sX) * abs(nX - sX) + (ll)abs(nY - sY) * abs(nY - sY) <= (ll)sR * sR);
    }
    
    void dfs(int n, int origin, int start, vector<bool>& visited, vector<vector<int>>& bombs){
        visited[start] = true;
        for (int neighbor = 0; neighbor < n; ++neighbor){
            if (visited[neighbor]) continue;
            int startX = bombs[start][0], startY = bombs[start][1], startR = bombs[start][2];
            int neighborX = bombs[neighbor][0], neighborY = bombs[neighbor][1], neighborR = bombs[neighbor][2];
            
            if (isOverlapped(startX, startY, startR, neighborX, neighborY))
                dfs(n, origin, neighbor, visited, bombs);
        }
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 0;
        for (int node = 0; node < n; ++node){
            vector<bool> visited(n);
            visited[node] = true;
            dfs(n, node, node, visited, bombs);
            int cnt = count(visited.begin(), visited.end(), true);
            ans = max(ans, cnt);
        }
        return ans;
    }
};