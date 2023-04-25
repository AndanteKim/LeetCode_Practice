class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        constexpr int SIZE = 26;
        vector<int> root(26);
        iota(root.begin(), root.end(), 0);
        
        function<int(int)> find = [&](int x){
            if (root[x] != x)
                root[x] = find(root[x]);
            return root[x];
        };
        
        auto unionSet = [&](int x, int y){
            int rx = find(x), ry = find(y);
            root[rx] = ry;
        };
        
        for (string& eqn : equations){
            if (eqn[1] == '='){
                int x = eqn[0] - 'a';
                int y = eqn[3] - 'a';
                unionSet(x, y);
            }
        }
        
        for (string& eqn : equations){
            if (eqn[1] == '!'){
                int x = eqn[0] - 'a';
                int y = eqn[3] - 'a';
                if (find(x) == find(y)) return false;
            }
        }
        
        return true;
    }
};