class Solution:
    def _sieve(self, upper_limit: int) -> List[int]:
        # Create an integer list to mark prime numbers (True = prime, False = not prime)
        sieve = [True] * (upper_limit + 1)
        sieve[0] = sieve[1] = False # 0 and 1 are not prime

        for num in range(2, int(upper_limit ** 0.5) + 1):
            if sieve[num]:
                # Mark all multiples of 'number' as non-prime
                for mult in range(num * num, upper_limit + 1, num):
                    sieve[mult] = False
        return sieve

    def closestPrimes(self, left: int, right: int) -> List[int]:
        # Step 1: Get all prime numbers up to 'right' using sieve
        sieve_array = self._sieve(right)

        prime_nums = [
            num for num in range(left, right + 1) if sieve_array[num]
        ]

        # Step 2: Find the closest prime pair
        if len(prime_nums) < 2:
            return -1, -1  # Less than two primes

        min_diff = float("inf")
        closest_pair = (-1, -1)

        for idx in range(1, len(prime_nums)):
            diff = prime_nums[idx] - prime_nums[idx - 1]
            if diff < min_diff:
                min_diff = diff
                closest_pair = prime_nums[idx - 1], prime_nums[idx]

        return closest_pair