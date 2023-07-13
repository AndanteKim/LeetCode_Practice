class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj, required, finished = [[] for _ in range(numCourses)], [[] for _ in range(numCourses)], [False] * numCourses
        
        for seq, need in prerequisites:
            adj[need].append(seq)
            required[seq].append(need)
        
        for numCourse in range(numCourses):
            if not finished[numCourse]:
                queue = deque([numCourse])
                
                while queue:
                    curr = queue.popleft()
                    flag = True
                    for course in required[curr]:
                        if not finished[course]:
                            flag = False
                    if flag:
                        finished[curr] = True
                        for next_sub in adj[curr]:
                            if not finished[next_sub]:
                                queue.append(next_sub)
            
        return True if all(finished) else False
                
                    
        