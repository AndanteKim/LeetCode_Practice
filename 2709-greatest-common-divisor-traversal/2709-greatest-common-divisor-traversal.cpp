class DSU{
private:
    vector<int> dsu, size;
    
public:
    DSU(int N){
        dsu.resize(N + 1);
        size.resize(N + 1);
        
        for (int i = 0; i <= N; ++i){
            dsu[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int x){
        return (dsu[x] == x)? x : dsu[x] = find(dsu[x]);
    }
    
    void merge(int x, int y){
        int fx = find(x), fy = find(y);
        
        if (fx == fy) return;
        
        if (size[fx] > size[fy]){
            int temp = fx;
            fx = fy;
            fy = temp;
        }
        
        dsu[fx] = fy;
        size[fy] += size[fx];
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int MAX = 100'000, N = nums.size();
        vector<bool> has(MAX + 1);
        
        for (int num:nums) has[num] = true;
        
        // edge cases
        if (N == 1) return true;
        
        if (has[1]) return false;
        
        // the general solution
        vector<int> sieve(MAX + 1);
        
        for (int d = 2; d <= MAX; ++d){
            if (sieve[d] == 0){
                for (int v = d; v <= MAX; v += d)
                    sieve[v] = d;
            }
        }
        
        DSU uf = DSU(2 * MAX + 1);
        for (int x:nums){
            int val = x;
            while (val > 1){
                int prime = sieve[val], root = prime + MAX;
                
                if (uf.find(root) != uf.find(x))
                    uf.merge(root, x);
                
                while (val % prime == 0) val /= prime;
            }
        }
        
        int cnt = 0;
        for (int i = 2; i <= MAX; ++i){
            if (has[i] && uf.find(i) == i) ++cnt;
        }
        
        return cnt == 1;
    }
};