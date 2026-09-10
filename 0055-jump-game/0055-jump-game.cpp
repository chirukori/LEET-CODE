class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_ele=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>max_ele) return false;
            max_ele=max(max_ele,i+nums[i]);
        }
        return true;
    }
};