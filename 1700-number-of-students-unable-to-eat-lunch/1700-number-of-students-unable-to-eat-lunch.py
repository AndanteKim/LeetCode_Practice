class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        circle_students_count, square_students_count = 0, 0
        
        # Count the number of students who want each type of sandwich
        for student in students:
            if student == 0:
                circle_students_count += 1
            else:
                square_students_count += 1
                
        # Serve sandwiches to students
        for sandwich in sandwiches:
            # No student wants the circle sandwich on top of the stack
            if sandwich == 0 and circle_students_count == 0:
                return square_students_count
            
            # No student wants the square sandwich on top of the stack
            if sandwich == 1 and square_students_count == 0:
                return circle_students_count
            
            # Decrement the count of the served sandwich type
            if sandwich == 0:
                circle_students_count -= 1
            else:
                square_students_count -= 1
        
        # Every student received a sandwich
        return 0