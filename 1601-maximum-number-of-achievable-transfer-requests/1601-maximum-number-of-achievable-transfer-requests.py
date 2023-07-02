class Solution:
    ans = 0
    def maxRequest(self, requests: List[List[int]], indegree: List[int], n: int, start: int, count: int) -> None:
        if (start == len(requests)):
            for i in range(n):
                if indegree[i]:
                    return
            
            self.ans = max(self.ans, count)
            return
        
        indegree[requests[start][0]] -= 1
        indegree[requests[start][1]] += 1
        
        self.maxRequest(requests, indegree, n, start + 1, count + 1)
        
        indegree[requests[start][0]] += 1
        indegree[requests[start][1]] -= 1
        
        self.maxRequest(requests, indegree, n, start + 1, count)
    
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        indegree = [0] * n
        self.maxRequest(requests, indegree, n, 0, 0)
        
        return self.ans  