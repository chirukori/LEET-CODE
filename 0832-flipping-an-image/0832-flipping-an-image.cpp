class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int n = image.size();
        for (auto& row : image) {
            int left = 0, right = n - 1;
            while (left <= right) {
                // When opposite elements are equal, both will change value after swap + invert.
                // If they are different, swapping then inverting results in the exact same values.
                if (row[left] == row[right]) {
                    row[left] ^= 1;
                    if (left != right) {
                        row[right] ^= 1;
                    }
                }
                left++;
                right--;
            }
        }
        return image;
    }
};