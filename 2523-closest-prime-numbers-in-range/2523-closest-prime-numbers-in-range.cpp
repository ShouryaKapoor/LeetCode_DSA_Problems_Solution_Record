class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        
        // Sieve of Eratosthenes to find primes efficiently
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Collect primes in the given range
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // If there are fewer than two primes, return {-1, -1}
        if (primes.size() < 2) {
            return {-1, -1};
        }

        // Find the closest prime pair
        int minDiff = INT_MAX;
        vector<int> result(2, -1);
        
        for (size_t i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }
        
        return result;
    }
};
