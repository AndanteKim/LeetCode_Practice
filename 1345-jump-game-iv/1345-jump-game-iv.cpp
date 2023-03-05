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
                
                for (int child : {node - 1, node + 1}){
                    if (other.find(child) != other.end()) return step + 1;
                    if (child >= 0 && child < arr.size() && !visited[child]){
                        visited[child] = true;
                        nex.insert(child);
                    }
                }
            }
            
            curs = nex;
            ++step;
        }
        return -1;
    }
};