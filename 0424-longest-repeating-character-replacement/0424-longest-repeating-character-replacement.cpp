class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlength=0;
        int maxfreq=0;
        vector<int> freq(26, 0);
        int l=0;
        int r=0;
        while(r<s.size()){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
        
        while((r-l+1)-maxfreq >k){
            freq[s[l]-'A']--;
            l++;
        }
            maxlength=max(maxlength,(r-l+1));
            r++;
        }
        return maxlength;
    }
};