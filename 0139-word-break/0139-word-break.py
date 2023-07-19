class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        words, seen = set(wordDict), set()
        queue = deque([0])
        
        while queue:
            i = queue.popleft()
            if i == len(s):
                return True
            
            for end in range(i + 1, len(s) + 1):
                if end in seen:
                    continue
                
                if s[i:end] in words:
                    queue.append(end)
                    seen.add(end)
            
        return False