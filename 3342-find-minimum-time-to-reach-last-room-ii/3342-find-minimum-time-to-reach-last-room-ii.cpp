class State{
public:
    int x, y, dis;
    State (int x, int y, int dis): x(x), y(y), dis(dis){}
};

class Solution {
private:
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    const int inf = 0x3f3f3f3f;

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<bool>> v(n, vector<bool>(m, false));

        auto cmp = [](const State& a, const State& b) {return a.dis > b.dis;};
        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        q.push(State(0, 0, 0));
        d[0][0] = 0;

        while (!q.empty()){
            State s = q.top(); q.pop();
            
            if (v[s.x][s.y]) continue;

            if (s.x == n - 1 && s.y == m - 1)
                break;

            v[s.x][s.y] = true;
            for (auto& [dx, dy] : dirs){
                int nx = s.x + dx, ny = s.y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int minDist = max(d[s.x][s.y], moveTime[nx][ny]) + (s.x + s.y) % 2 + 1;
                if (d[nx][ny] > minDist){
                    d[nx][ny] = minDist;
                    q.push(State(nx, ny, minDist));
                }
            }
        }

        return d[n - 1][m - 1];
    }
};