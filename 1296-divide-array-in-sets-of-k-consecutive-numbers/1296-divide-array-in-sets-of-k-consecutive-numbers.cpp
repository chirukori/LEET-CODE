class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() %  k!= 0) {
            return false;
        }
 
        map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
 
        for (auto const& [num, freq] : count) {
            if (freq > 0) {
                int startCount = freq;
                for (int i = 0; i < k; ++i) {
                    if (count[num + i] < startCount) {
                        return false;
                    }
                    count[num + i] -= startCount;
                }
            }
        }

        return true;
    }
};