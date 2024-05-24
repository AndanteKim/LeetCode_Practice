class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        def backtrack(i: int, remain: Dict[int, int]) -> int:
            if i == n:
                return 0
            
            total_score, used = 0, True
            word = Counter(words[i])
            for c, freq in word.items():
                if freq > remain[c]:
                    used = False
                    break
            
            if used:
                for c, freq  in word.items():
                    remain[c] -= freq
                    total_score += freq * score[ord(c) - 97]
                    
                total_score += backtrack(i + 1, remain)
                
                for c, freq in word.items():
                    remain[c] += freq
                
                total_score = max(total_score, backtrack(i + 1, remain))
                
            else:
                total_score = backtrack(i + 1, remain)
                
            return total_score
        
        
        n, remain = len(words), Counter(letters)
            
        return backtrack(0, remain)