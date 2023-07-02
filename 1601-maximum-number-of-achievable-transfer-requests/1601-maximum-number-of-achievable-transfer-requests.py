class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        ans = 0
        
        for mask in range(1 << len(requests)):
            indegree = [0] * n
            pos = len(requests) - 1
            bit_count = bin(mask).count('1')
            
            if bit_count <= ans:
                continue
            
            curr = mask
            while curr > 0 and pos >= 0:
                if curr & 1:
                    indegree[requests[pos][0]] -= 1
                    indegree[requests[pos][1]] += 1
                curr >>= 1
                pos -= 1
            
            flag = 1
            for i in range(n):
                if indegree[i]:
                    flag = 0
                    break
            
            if flag:
                ans = bit_count
        return ans