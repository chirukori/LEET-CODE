class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int currentSum = 0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            currentSum += cardPoints[i];
        }
        int maxsum=currentSum;
        for (int i = 0; i < k; i++) {
            currentSum -= cardPoints[k - 1 - i]; 
            currentSum += cardPoints[n - 1 - i]; 
            maxsum = max(maxsum, currentSum);
        }
        return maxsum;
    }
};