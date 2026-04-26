using st = size_t;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto prev = nums[0];
        auto n = nums.size();
        bool ifDuplicate = false;
        for (st i = 1; i < n; i++) {
            if (prev == nums[i]) {
                ifDuplicate = true;
                break;
            }
            prev = nums[i];
        }
        return ifDuplicate;
    }
};
