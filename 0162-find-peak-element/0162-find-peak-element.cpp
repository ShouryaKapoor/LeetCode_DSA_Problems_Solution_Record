class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                right = mid; // Peak lies in the left half
            } else {
                left = mid + 1; // Peak lies in the right half
            }
        }
        return left; // 'left' will be at the peak element index
    }
};
