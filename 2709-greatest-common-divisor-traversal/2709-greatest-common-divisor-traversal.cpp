class Graph{
private:
    int n;
    vector<vector<int>> edges;
    void traverse(int x, vector<bool>& visited){
        queue<int> q;
        q.push(x);
        visited[x] = true;
        while(!q.empty()){
            x = q.front(); q.pop();
            for (int y : edges[x]){
                if (!visited[y]){
                    q.push(y);
                    visited[y] = true;
                }
            }
        }
    }

public:
    Graph(int n = 0) : n(n){
        edges.resize(n);
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
    vector<int> getPrimeFactor(int x){
        vector<int> primeFactors;
        for (int i = 2; i * i <= x; ++i){
            if (x % i == 0){
                primeFactors.push_back(i);
                while (x % i == 0) x /= i;
            }
        }
        
        if (x != 1) primeFactors.push_back(x);
        
        return primeFactors;
    }
    
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        
        Graph g(n);
        unordered_map<int, int> seen;
        for (int i = 0; i < n; ++i){
            if (nums[i] == 1) return false;
            
            vector<int> primeFactors = getPrimeFactor(nums[i]);
            for (int prime : primeFactors){
                if (seen.count(prime)){
                    g.addEdge(i, seen[prime]);
                }
                else{
                    seen[prime] = i;
                }
            }
        }
        
        return g.isConnected();
    }
};