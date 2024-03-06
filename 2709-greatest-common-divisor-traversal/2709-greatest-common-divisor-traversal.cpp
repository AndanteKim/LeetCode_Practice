class Graph{
private:
    int n;
    vector<vector<int>> edges;
    
public:
    Graph(int n = 0) : n(n){
        edges.resize(n);
    }
    
    void traverse(int x, vector<bool>& visited){
        visited[x] = true;
        for (int y : edges[x]){
            if (!visited[y])
                traverse(y, visited);
        }
    }
    
    void addEdge(int x, int y){
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    
    bool isConnected(){
        vector<bool> visited(n);
        traverse(0, visited);
        return count(visited.begin(), visited.end(), true) == n;
    }
};


class Solution {
private:
    vector<int> getPrimeFactors(int x){
        vector<int> primes;
        for (int i = 2; i * i <= x; ++i){
            if (x % i == 0){
                while (x % i == 0)
                    x /= i;
                primes.push_back(i);
            }
        }
        
        if (x != 1) primes.push_back(x);
        
        return primes;
    }
    
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        // DFS
        int n = nums.size();
        if (n == 1) return true;
        
        Graph g(n);
        unordered_map<int, int> seen;
        
        for (int i = 0; i < n; ++i){
            if (nums[i] == 1) return false;
            
            for (int prime : getPrimeFactors(nums[i])){
                if (seen.find(prime) != seen.end())
                    g.addEdge(i, seen[prime]);
                else
                    seen[prime] = i;
            }
        }
        
        return g.isConnected();
    }
};