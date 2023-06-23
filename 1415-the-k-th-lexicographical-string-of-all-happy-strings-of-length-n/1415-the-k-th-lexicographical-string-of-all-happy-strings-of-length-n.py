class Solution:
    def backtrack(self, start: int, word: List[str], n: int, k: int, ans_list: List[str]) -> None:
        if start == n:
            ans_list.append("".join(word))
            return
        
        for c in "abc":
            if word and word[-1] == c:
                continue
            else:
                word.append(c)
                self.backtrack(start + 1, word, n, k, ans_list)
                word.pop()
    
    def getHappyString(self, n: int, k: int) -> str:
        ans_list = []
        
        self.backtrack(0, [], n, k, ans_list)
        
        return "" if len(ans_list) < k else ans_list[k - 1]