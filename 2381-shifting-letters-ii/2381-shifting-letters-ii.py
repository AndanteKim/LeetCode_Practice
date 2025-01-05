class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        diff_arr = [0] * n

        for start, end, direction in shifts:
            if direction == 1:
                diff_arr[start] += 1

                if end + 1 < n:
                    diff_arr[end + 1] -= 1
                
            else:
                diff_arr[start] -= 1

                if end + 1 < n:
                    diff_arr[end + 1] += 1
        
        ans, num_of_shifts = "", 0
        
        for i in range(n):
            num_of_shifts += diff_arr[i]
            num_of_shifts %= 26
            ans += chr(97 + (ord(s[i]) - 97 + num_of_shifts) % 26)
        
        return ans
            