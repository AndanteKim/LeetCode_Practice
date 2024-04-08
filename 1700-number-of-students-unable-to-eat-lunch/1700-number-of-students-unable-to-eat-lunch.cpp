class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circleStudentsCount = 0, squareStudentsCount = 0;
        
        // Count the number of students who want each type of sandwich
        for (int student : students){
            if (student == 0) ++circleStudentsCount;
            else ++squareStudentsCount;
        }
        
        // Serve sandwiches to students
        for (int sandwich : sandwiches){
            if (sandwich == 0){
                // No student wants the circle sandwich on top of the stack
                if (circleStudentsCount == 0) return squareStudentsCount;
                // Decrement the count of the served sandwich type
                --circleStudentsCount;
            }
            else{
                // No student wants the square sandwich on top of the stack
                if (squareStudentsCount == 0) return circleStudentsCount;
                // Decrement the count of the served sandwich type
                --squareStudentsCount;
            }
        }
        
        // Every student received a sandwich
        return 0;
    }
};