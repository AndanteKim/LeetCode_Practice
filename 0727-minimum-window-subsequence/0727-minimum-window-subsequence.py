class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        n, m = len(s1), len(s2)
        ans = ""
        indices = defaultdict(list)
        
        for i in range(n):
            indices[s1[i]].append(i)
        
        ind = [0] * m
        for start in range(n):
            prev = start - 1
            notFound = False
            for j in range(m):
                if s2[j] not in indices:
                    return ""
                cur_indices = indices[s2[j]]
                
                while ind[j] < len(cur_indices) and cur_indices[ind[j]] <= prev:
                    ind[j] += 1
                if ind[j] == len(cur_indices):
                    return ans
                prev = cur_indices[ind[j]]
            if ans == "" or prev - start + 1 < len(ans):
                ans = s1[start: prev + 1]
        return ans