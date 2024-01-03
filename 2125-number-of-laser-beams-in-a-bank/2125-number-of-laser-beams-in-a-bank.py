class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        row_constitute, m, ans = [], len(bank), 0
        for row in bank:
            num_camera = row.count('1')
            if num_camera:
                row_constitute.append(num_camera)
        
        for i in range(1, len(row_constitute)):
            ans += row_constitute[i - 1] * row_constitute[i]
            
        return ans