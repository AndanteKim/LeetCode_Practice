class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses), required(numCourses);
        vector<bool> finished(numCourses);
        
        for (vector<int>& prerequisite : prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
            required[prerequisite[0]].push_back(prerequisite[1]);
        }
        
        for (int numCourse = 0; numCourse < numCourses; ++numCourse){
            if (!finished[numCourse]){
                queue<int> queue{{numCourse}};
                
                while (!queue.empty()){
                    int curr = queue.front();
                    queue.pop();
                    
                    int flag = true;
                    for (int course : required[curr]){
                        if (!finished[course]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag){
                        finished[curr] = true;
                        for (int seq : adj[curr]){
                            if (!finished[seq]){
                                queue.push(seq);
                            }
                        }
                    }
                }
            }
        }
        
        return count(finished.begin(), finished.end(), true) == numCourses? true : false;
    }
};