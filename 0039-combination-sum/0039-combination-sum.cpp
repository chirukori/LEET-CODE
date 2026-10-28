class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> current;
        
        // Sorting helps prune branches early
        sort(candidates.begin(), candidates.end());
        
        backtrack(0, target, candidates, current, results);
        return results;
    }

private:
    void backtrack(int start, int remaining, const vector<int>& candidates, 
                   vector<int>& current, vector<vector<int>>& results) {
  
        if (remaining == 0) {
            results.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
   
            if (candidates[i] > remaining) {
                break;
            }
            current.push_back(candidates[i]);
            backtrack(i, remaining - candidates[i], candidates, current, results);
            current.pop_back();
        }
    }
};