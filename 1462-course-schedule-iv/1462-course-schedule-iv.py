class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        is_prerequisite = [[False] * numCourses for _ in range(numCourses)]

        for start, end in prerequisites:
            is_prerequisite[start][end] = True

        for stopover in range(numCourses):
            for start in range(numCourses):
                for end in range(numCourses):
                    # If there is a path start -> stopover and stopover -> target, then start -> end exists as well
                    is_prerequisite[start][end] = is_prerequisite[start][end] or (is_prerequisite[start][stopover] \
                    and is_prerequisite[stopover][end])
        
        ans = []
        for start, end in queries:
            ans.append(is_prerequisite[start][end])

        return ans