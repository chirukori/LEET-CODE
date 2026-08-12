class Solution {
public:
 long long calculateTotalHours(vector<int>& a, int hourly) {
        long long totalHours = 0;
        for (int pile : a) {
            totalHours += (pile + hourly - 1) / hourly;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;  
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            long long hours = calculateTotalHours(piles, mid);
            if (hours <= h) {
                ans = mid;      
                high = mid - 1;  
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
  
};