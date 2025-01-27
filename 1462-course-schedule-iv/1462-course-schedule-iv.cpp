class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector isPrerequisite(numCourses, vector<bool>(numCourses));

        for (const auto& prerequisite : prerequisites){
            int start = prerequisite[0], end = prerequisite[1];
            isPrerequisite[start][end] = true;
        }

        for (int stopOver = 0; stopOver < numCourses; ++stopOver){
            for (int start = 0; start < numCourses; ++start){
                for (int end = 0; end < numCourses; ++end){
                    // If there's a path start -> stopOver and stopOver -> end, then start -> end exists as well.
                    isPrerequisite[start][end] = isPrerequisite[start][end] || \
                    (isPrerequisite[start][stopOver] && isPrerequisite[stopOver][end]);
                }
            }
        }
        
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i){
            int start = queries[i][0], end = queries[i][1];
            ans[i] = isPrerequisite[start][end];
        }

        return ans;
    }
};