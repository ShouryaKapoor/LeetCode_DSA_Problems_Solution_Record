class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Check if all elements have even frequency
        for (const auto &pair : freq) {
            if (pair.second % 2 != 0) {
                return false;  // If any count is odd, return false
            }
        }
        
        return true;  // If all counts are even, return true
    }
};
