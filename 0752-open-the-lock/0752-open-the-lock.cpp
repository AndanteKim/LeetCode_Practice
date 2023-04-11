class Solution {
    vector<string> neighbors(string& node){
        vector<string> node_bfs;
        for (int i = 0; i < 4; ++i){
            int num = int(node[i] - '0');
            for (int change : {-1, 1}){
                int x = (num + change + 10) % 10;
                node_bfs.push_back(node.substr(0, i) + (char)(x + 48) + node.substr(i+1));
            }
        }
        
        return node_bfs;
    }
    
public:
    int openLock(vector<string>& deadends, string target) {
        if (find(deadends.begin(), deadends.end(), "0000") != deadends.end()) return -1;
        
        queue<pair<string, int>> queue;
        queue.push({"0000", 0});
        unordered_set<string> seen(deadends.begin(), deadends.end());
        seen.insert("0000");
        
        while (!queue.empty()){
            auto it = queue.front();
            queue.pop();
            string node = it.first;
            int steps = it.second;
            if (node == target) return steps;
            for (string& neighbor : neighbors(node)){
                if (seen.find(neighbor) == seen.end()){
                    seen.insert(neighbor);
                    queue.push({neighbor, steps + 1});
                }
            }
        }
        
        return -1;
    }
};