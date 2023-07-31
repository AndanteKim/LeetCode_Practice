class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        if len(s1) < len(s2):
            return self.minimumDeleteSum(s2, s1)
        
        m, n = len(s1), len(s2)
        curr_row = [0] * (n + 1)
        for j in range(1, n + 1):
            curr_row[j] = curr_row[j - 1] + ord(s2[j - 1])
            
        for i in range(1, m + 1):
            diagonal = curr_row[0]
            curr_row[0] += ord(s1[i - 1])
            
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    answer = diagonal
                else:
                    answer = min(ord(s1[i - 1]) + curr_row[j], ord(s2[j - 1]) + curr_row[j - 1])
                
                diagonal = curr_row[j]
                curr_row[j] = answer
        return curr_row[-1]
        