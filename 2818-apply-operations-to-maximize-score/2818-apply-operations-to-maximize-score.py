class Solution:
    mod = 10 ** 9 + 7
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prime_scores = [0] * n

        # Calculate the prime score for each number in nums
        for idx in range(n):
            num = nums[idx]

            # Check for prime factors from 2 to sqrt(n)
            for factor in range(2, int(num ** 0.5) + 1):
                if num % factor == 0:
                    # Increment prime score for each prime factor
                    prime_scores[idx] += 1

                    # Remove all occurrences of the prime factor from num
                    while num % factor == 0:
                        num //= factor

            # If num is still greater than or equal to 2, it's a prime factor
            if num >= 2:
                prime_scores[idx] += 1

        # Initialize next and previous dominant index arrays
        next_dominant = [n] * n
        prev_dominant = [-1] * n

        # Stack to store indices for monotonic decreasing for each number
        decreasing_prime_score_stack = []

        # Calculate the next and previous dominant indices for each number
        for idx in range(n):
            # While the stack is not empty and the current prime score is greater than the stack's top
            while (decreasing_prime_score_stack and prime_scores[decreasing_prime_score_stack[-1]] < prime_scores[idx]):
                top_idx = decreasing_prime_score_stack.pop()

                # Set the next dominant element for the popped index
                next_dominant[top_idx] = idx
            
            # If the stack is not empty, set the previous dominant element for the current index
            if decreasing_prime_score_stack:
                prev_dominant[idx] = decreasing_prime_score_stack[-1]

            # Push the current index onto the stack
            decreasing_prime_score_stack.append(idx)

        # Calculate the number of subarrays in which each element is dominant
        num_of_subarrays = [0] * n
        for idx in range(n):
            num_of_subarrays[idx] = (next_dominant[idx] - idx) * (idx - prev_dominant[idx])

        # Priority queue to process elements in decreasing orer of their value
        processing_queue = []

        # Push each number and its index onto the priority queue
        for idx in range(n):
            heappush(processing_queue, (-nums[idx], idx))

        score = 1

        # Helper function to compute the power of a number modulo MOD
        def _power(base: int, exponent: int) -> int:
            res = 1

            # Calculate the exponentiation using binary exponentiation
            while exponent > 0:
                # If the exponent is odd, multiply the result by the base
                if exponent % 2 == 1:
                    res = (res * base) % self.mod
                
                # Square the base and halve the exponent
                base = (base * base) % self.mod
                exponent >>= 1

            return res

        # Process elements while there are operations left
        while k > 0:
            # Get the element with the maximum value from the queue
            num, idx = heappop(processing_queue)
            num = -num  # Negate back to positive

            # Calculate the number of operations to apply on the current element
            operations = min(k, num_of_subarrays[idx])

            # Update the score by raising the element to the power of operations
            score = (score * _power(num, operations)) % self.mod

            # Reduce the remaining operations count
            k -= operations

        return score

