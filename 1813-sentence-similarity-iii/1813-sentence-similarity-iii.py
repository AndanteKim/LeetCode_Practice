class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1, s2 = sentence1.split(), sentence2.split()
        dq1, dq2 = deque(s1), deque(s2)
        
        # Compare the longest common prefix
        while dq1 and dq2 and dq1[0] == dq2[0]:
            dq1.popleft()
            dq2.popleft()
            
        # Compare the longest common suffix
        while dq1 and dq2 and dq1[-1] == dq2[-1]:
            dq1.pop()
            dq2.pop()
        
        return len(dq1) == 0 or len(dq2) == 0