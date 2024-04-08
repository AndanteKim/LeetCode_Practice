class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        n = len(students) # Sandwiches will be the same length
        student_queue, sandwich_stack = deque(), []
        
        # Add students and sandwiches to the queue and staack
        for i in range(n):
            sandwich_stack.append(sandwiches[n - i - 1])
            student_queue.append(students[i])
        
        # Simulate the lunch process by serving sandwiches
        # or sending students to the back of the queue.
        last_served = 0
        
        while len(student_queue) > 0 and last_served < len(student_queue):
            if sandwich_stack[-1] == student_queue[0]:
                sandwich_stack.pop() # Serve sandwich
                student_queue.popleft() # Student leaves queue
                last_served = 0
                
            else:
                # Student moves to back of queue
                student_queue.append(student_queue.popleft())
                last_served += 1
                
        # Remaining students in queue are unserved students
        return len(student_queue)