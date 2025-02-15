class Solution:
    def punishmentNumber(self, n: int) -> int:
        def find_partitions(start_idx: int, curr_sum: int) -> bool:
            # Check if partition is valid
            if start_idx == len(str_num):
                return curr_sum == curr_num
            
            # Invalid partition found, so we return False
            if curr_sum > curr_num:
                return False

            # If the result for this state is already calculated, return it
            if memo[start_idx][curr_sum] != -1:
                return memo[start_idx][curr_sum] == 1

            partition_found = False

            # Iterate through all possible substrings starting with start_idx
            for curr_idx in range(start_idx, len(str_num)):
                # Create partition
                curr_str = str_num[start_idx : curr_idx + 1]
                add_end = int(curr_str)

                # Recursivelyu check if valid partition can be found
                partition_found = partition_found or find_partitions(
                    curr_idx + 1, curr_sum + add_end
                )

                if partition_found:
                    memo[start_idx][curr_sum] = 1
                    return True
            
            # Memoize the result for future reference and return its result
            memo[start_idx][curr_sum] = 0
            return False


        ans = 0
        
        # Iterate through numbers in range [1, n]
        for curr_num in range(1, n + 1):
            sq_num = curr_num * curr_num
            str_num = str(sq_num)

            # Initialize values in memoization array
            memo = [[-1] * (curr_num + 1) for _ in range(len(str_num))]

            # Check if valid partition can be found and add squared number if so
            if find_partitions(0, 0):
                ans += sq_num

        return ans
