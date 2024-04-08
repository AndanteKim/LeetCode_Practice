class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        queue, n = deque(students), len(sandwiches)
        square_students = students.count(1)
        circular_students = n - square_students
        # Make sandwiches array like a stack 
        sandwiches = sandwiches[::-1]
        
        while queue and sandwiches:
            curr = queue.popleft()  
            
            # If the current student finds the sandwich they want, then take and leave
            if curr == sandwiches[-1]:
                status = sandwiches.pop()
                if status == 0:
                    circular_students -= 1
                else:
                    square_students -= 1
            # Otherwise, they will leave it and go back to the end of queue
            else:
                queue.append(curr)
                if (sandwiches[-1] == 0 and circular_students == 0) or (sandwiches[-1] == 1 and square_students == 0):
                    break
        
        # Return the students unable to eat
        return len(queue)