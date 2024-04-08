class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        int n = students.size(), squareStudents = count(students.begin(), students.end(), 1),\
            circularStudents = n - squareStudents;
        
        for (int i = 0; i < n; ++i){
            q.push(students[i]);
            st.push(sandwiches[n - 1 - i]);
        }
        
        while (!q.empty() && !st.empty()){
            // If the current student finds the sandwich they want, then take it and leave
            if (q.front() == st.top()){
                if (q.front() == 1) --squareStudents;
                else --circularStudents;
                q.pop();
                st.pop();
            }
            // Otherwise, they will leave it and go back to the end of queue
            else{
                int curr = q.front(); q.pop();
                q.push(curr);
                // If we're not able to progress next step due to not enough students wanting their desired sandwich
                // , then stop this loop
                if ((st.top() == 0 && circularStudents == 0) || (st.top() == 1 && squareStudents == 0)) break;
            }
            
        }
        
        return q.size();
    }
};