class Solution {
    vector<pair<int,int>> pairs{{0,0}, {1,1}, {6,9}, {8,8}, {9,6}};
    int dfs(long num, long rot, long p, int n){
        int cnt = 0;
        if (num != rot) ++cnt;
        for (auto [x,y] : pairs){
            if (num == 0 && x == 0) continue;
            if (num * 10 + x > n) break;
            cnt += dfs(num * 10 + x, y * p + rot, p * 10, n);
        }
        
        return cnt;
    }
    
public:
    
    int confusingNumberII(int n) {
        return dfs(0, 0, 1, n);
    }
};