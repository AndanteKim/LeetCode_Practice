class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return [""]
        
        ans = []
        
        for left_count in range(n):
            for left_string in self.generateParenthesis(left_count):
                for right_string in self.generateParenthesis(n - 1 - left_count):
                    ans.append("(" + left_string + ")" + right_string)
                    
        return ans