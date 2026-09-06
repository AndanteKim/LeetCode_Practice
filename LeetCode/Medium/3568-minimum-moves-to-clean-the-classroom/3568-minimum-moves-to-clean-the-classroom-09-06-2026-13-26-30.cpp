class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector id(m, vector<int>(n));
        int sx, sy, cnt = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') id[i][j] = 1 << cnt++;
            }
        }
        
        vector bestE(m, vector(n, vector<int>(1 << cnt, -1)));
        bestE[sx][sy][0] = energy;
        struct Info {
            int x, y, mask, e, steps;
        };

        queue<Info> q;
        q.push({sx, sy, 0, energy, 0});

        while (!q.empty()) {
            Info t = q.front(); q.pop();
            if (t.mask == (1 << cnt) - 1) return t.steps;

            if (t.e == 0) continue;

            for (const auto& [newX, newY] : vector<pair<int, int>>{{t.x - 1, t.y}, {t.x + 1, t.y}, {t.x, t.y - 1}, {t.x, t.y + 1}}) {
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || classroom[newX][newY] == 'X') {
                    continue;
                }

                int newE = classroom[newX][newY] == 'R'? energy : t.e - 1;
                int newMask = t.mask | id[newX][newY];
                if (newE > bestE[newX][newY][newMask]) {
                    bestE[newX][newY][newMask] = newE;
                    q.push({newX, newY, newMask, newE, t.steps + 1});
                }
            }
        }

        return -1;
    }
};