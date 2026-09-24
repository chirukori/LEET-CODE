class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int digitsum=0;
            while(val>0){
                digitsum+=val%10;
                val/=10;
            }
            if (digitsum == i) {
                return i;
            }
        }
        return -1;
    }
};