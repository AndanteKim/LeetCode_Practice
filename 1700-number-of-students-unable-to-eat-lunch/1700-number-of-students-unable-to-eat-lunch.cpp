class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circleStudentsCount = 0, squareStudentsCount = 0;
        
        for (int student : students){
            if (student == 0) ++circleStudentsCount;
            else ++squareStudentsCount;
        }
        
        for (int sandwich : sandwiches){
            if (sandwich == 0){
                if (circleStudentsCount == 0) return squareStudentsCount;
                --circleStudentsCount;
            }
            else{
                if (squareStudentsCount == 0) return circleStudentsCount;
                --squareStudentsCount;
            }
        }
        
        return 0;
    }
};