class Solution:
    def countAndSay(self, n: int) -> str:
        def recursive(i: int, curr: str) -> str:
            if i == n:
                return curr

            nxt, curr_num, cnt = "", '', 0
            for c in curr:
                if curr_num == "" or c == curr_num:
                    cnt += 1
                else:
                    nxt += str(cnt) + curr_num
                    cnt = 1
                curr_num = c
            
            nxt += str(cnt) + curr_num
            return recursive(i + 1, nxt)
        
        return recursive(1, '1')