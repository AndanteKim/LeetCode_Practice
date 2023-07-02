class Solution {
private:
    int ans = 0;
    void maxRequests(vector<vector<int>>& requests, vector<int>& indegree, int n, int start, int count){
        if (start == requests.size()){
            for (int i = 0; i < n; ++i){
                if (indegree[i]) return;
            }
            ans = max(ans, count);
            return;
        }
        
        --indegree[requests[start][0]];
        ++indegree[requests[start][1]];
        maxRequests(requests, indegree, n, start + 1, count + 1);
        ++indegree[requests[start][0]];
        --indegree[requests[start][1]];
        
        maxRequests(requests, indegree, n, start + 1, count);
    }
    
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n);
        maxRequests(requests, indegree, n, 0, 0);
        return ans;
    }
};