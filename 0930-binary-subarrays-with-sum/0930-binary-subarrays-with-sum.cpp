class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        int count = 0, sum = 0;
        prefixSumCount[0] = 1;
        for (int num : nums) { 
            sum += num;
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[sum - goal];
            }
            prefixSumCount[sum]++;
        }
        return count;
    }
};