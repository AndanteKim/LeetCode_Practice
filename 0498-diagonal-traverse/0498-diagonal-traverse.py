class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        # Check for empty matrices
        if not mat or not mat[0]:
            return []

        # Variables to track the size of the matrix
        R, C = len(mat), len(mat[0])

        # The two arrays as explained in the algorithm
        ans, curr = [],[]

        # We have to go over all the elements in the first
        # row and the last column to cover all possible diagonals
        for d in range(R + C - 1):
            # Clear the intermediate array everytime we start
            # to process another diagonal
            curr.clear()
            r, c = 0 if d < C else d - C + 1, d if d < C else C - 1

            # Iterate until one of the indices goes out of scope
            # Take note of the index math to go down the diagonal
            while r < R and c > -1:
                curr.append(mat[r][c])
                r += 1
                c -= 1

            # Reverse even numbered diagonals. The article says
            # we have to reverse odd numbered articles but here,
            # the numbering is starting from 0.
            if d % 2 == 0:
                ans.extend(curr[::-1])
            else:
                ans.extend(curr)

        return ans
