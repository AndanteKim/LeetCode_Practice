class Solution:
    def largestPalindromic(self, num: str) -> str:
        cnt = [0] * 10
        for c in num:
            cnt[int(c)] += 1
        
        front, rear = "", ""
        
        for i in range(9, -1, -1):
            if i == 0 and front == "":
                continue
            
            while cnt[i] > 1:
                front += str(i)
                rear += str(i)
                cnt[i] -= 2
        
        for i in range(9, -1, -1):
            if cnt[i]:
                front += str(i)
                break
        
        return front + rear[::-1]