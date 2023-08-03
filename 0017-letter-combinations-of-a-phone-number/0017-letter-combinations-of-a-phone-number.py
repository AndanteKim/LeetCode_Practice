class Solution:
    def backtrack(self, ans: List[str], start: int, curr: List[chr], digits: str, letters_table: Dict[chr, str]) -> None:
        # base case
        if len(curr) == self.n:
            ans.append("".join(curr))
            return
        
        for i in range(start, self.n):
            for c in letters_table[digits[i]]:
                curr.append(c)
                self.backtrack(ans, i + 1, curr, digits, letters_table)
                curr.pop()
    
    def letterCombinations(self, digits: str) -> List[str]:
        letters_table = {'2': "abc", '3': "def", '4': "ghi", '5': "jkl",\
                         '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz"}
        ans, self.n = [], len(digits)
        if self.n == 0:
            return ans
        self.backtrack(ans, 0, [], digits, letters_table)
        
        return ans