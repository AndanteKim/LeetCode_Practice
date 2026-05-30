class Solution:
    def confusingNumber(self, n: int) -> bool:
        rotated = {'0':'0', '1':'1', '6':'9', '8':'8', '9':'6'}
        invalid = {'2', '3', '4', '5', '7'}
        num = [c for c in str(n)]
        r_num = num[:]

        for i in range(len(num)):
            if num[i] in invalid:
                return False
            r_num[i] = rotated[num[i]]

        return r_num[::-1] != num