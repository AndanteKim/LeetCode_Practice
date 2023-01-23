class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        ans = -1
        trust_give = {i:set() for i in range(1, n+1)}
        trust_receive = {i:set() for i in range(1, n+1)}
        
        for a_i, b_i in trust:
            trust_give[a_i].add(b_i)
            trust_receive[b_i].add(a_i)
        
        candidates = []
        
        for key, val in trust_receive.items():
            if len(val) == n-1:
                candidates.append(key)
        
        for candidate in candidates:
            if trust_give[candidate] == set():
                ans = candidate
        
        return ans