class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto firstZero=upper_bound(nums.begin(),nums.end(),-1), minPos = upper_bound(nums.begin(), nums.end(),0);
        int left = firstZero-nums.begin(), right = minPos - nums.begin();
        if(right==nums.size())
            right=0;
        else
        if(nums[right]>0)
            right = nums.size() - right;
        return max(left,right);
    }
};