class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def check(x: int) -> int:
            # How many rotations should be done
            # to have all elements in A == x
            # and to have all elements in B equal to X
            rot_t = rot_b = 0

            for i in range(n):
                # rotations couldn't be done
                if tops[i] != x and bottoms[i] != x:
                    return -1
                # tops[i] != x and bottoms[i] == x:
                elif tops[i] != x:
                    rot_t += 1
                # tops[i] == x and bottoms[i] != x:
                elif bottoms[i] != x:
                    rot_b += 1
            
            # min number of rotations to have all
            # elements equal to x in tops or bottoms
            return min(rot_t, rot_b)

        n = len(tops)
        rotations = check(tops[0])
        # If one could make all elements in top or bottom equal to top[0]
        if rotations != -1 or tops[0] == bottoms[0]:
            return rotations
        # If one could make all elements in A or B equal to B[0]
        else:
            return check(bottoms[0])