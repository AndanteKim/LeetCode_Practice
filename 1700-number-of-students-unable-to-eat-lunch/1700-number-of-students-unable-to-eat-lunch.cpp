class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue;
        stack<int> sandwichStack;
        int n = students.size(); // the size of sandwiches would be the same length
        
        // Add students and sandwiches to the queue and stack
        for (int i = 0; i < n; ++i){
            studentQueue.push(students[i]);
            sandwichStack.push(sandwiches[n - 1 - i]);
        }
        
        // Simulate the lunch process by serving sandwiches
        // or sending students to the back of queue.
        int lastServed = 0;
        while (!studentQueue.empty() && lastServed < studentQueue.size()){
            if (sandwichStack.top() == studentQueue.front()){
                sandwichStack.pop(); // serve sandwich
                studentQueue.pop();  // student leaves queue
                lastServed = 0;
            }
            else{
                // student moves to back of queue
                int curr = studentQueue.front(); studentQueue.pop();
                studentQueue.push(curr);
                ++lastServed;
            }
        }
        
        // Remaining students in queue are unserved students
        return studentQueue.size();
    }
};