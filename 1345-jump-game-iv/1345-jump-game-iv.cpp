class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) graph[arr[i]].push_back(i);
        set<int> curs, other;
        curs.insert(0);
        other.insert(n-1);
        vector<bool> visited(n, false);
        int step = 0;
        
        while (!curs.empty()){
            if (curs.size() > other.size()) swap(curs, other);
            set<int> nex;
            
            for (int node : curs){
                for (int child : graph[arr[node]]){
                    if (other.find(child) != other.end()) return step + 1;
                    if (!visited[child]){
                        visited[child] = true;
                        nex.insert(child);
                    }
                }
                graph.erase(arr[node]);
                
                if (other.find(node + 1) != other.end() || other.find(node - 1) != other.end()) return step + 1;
                if (node + 1 < n && !visited[node + 1]){
                    visited[node + 1] = true;
                    nex.insert(node + 1);
                }
                if (node - 1 >= 0 && !visited[node - 1]){
                    visited[node - 1] = true;
                    nex.insert(node - 1);
                }
            }
            
            curs = nex;
            ++step;
        }
        return -1;
    }
};