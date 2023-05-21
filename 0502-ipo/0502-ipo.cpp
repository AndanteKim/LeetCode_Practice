class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), i = 0;
        vector<pair<int, int>> projects;
        
        for (int j = 0; j < n; ++j){
            projects.push_back({capital[j], profits[j]});
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> heap;
        
        for (int it = 0; it < k; ++it){
            while (i < n && projects[i].first <= w){
                heap.push(projects[i].second);
                ++i;
            }
            if (heap.size() == 0) return w;
            w += heap.top();
            heap.pop();
        }
        
        return w;
    }
};