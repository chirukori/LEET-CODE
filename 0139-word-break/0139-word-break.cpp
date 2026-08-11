class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        
         
        int maxLen = 0;
        for (const string& word : wordDict) {
            maxLen = max(maxLen, (int)word.length());
        }

        
        vector<bool> dp(n + 1, false);
        dp[0] = true;  

        for (int i = 1; i <= n; ++i) { 
            for (int j = i - 1; j >= 0; --j) {
               
                if (i - j > maxLen) {
                    break;
                }
                
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;   
                }
            }
        }

        return dp[n];
    }
};