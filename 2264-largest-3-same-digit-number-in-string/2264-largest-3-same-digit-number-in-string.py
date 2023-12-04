class Solution:
    def largestGoodInteger(self, num: str) -> str:
        ans, matching = "", {"000":0,"111":111,"222":222, "333":333,\
                            "444":444,"555":555,"666":666,\
                            "777":777,"888":888,"999":999}
        i, j = 0, 0
        while j < len(num):
            if j - i == 2 and num[i] == num[j]:
                curr = num[i:j+1]
                if ans == "" or matching[curr] > matching[ans]:
                    ans = curr
            
            if num[i] == num[j]:
                j += 1
            else:
                i = j
            
        
        return ans