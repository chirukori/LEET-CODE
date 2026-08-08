class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMp, sMp;
        for (char ch : t) {
            tMp[ch]++;
        }

        int required = tMp.size();
        int formed = 0;
        int l = 0;
        int resLeft = 0;
        int minLen = INT_MAX;

        for (int r = 0; r < s.length(); r++) {
            char ch = s[r];
            
            if (tMp.count(ch)) {
                sMp[ch]++;
                if (sMp[ch] == tMp[ch]) {
                    formed++;
                }
            }

            while (formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    resLeft = l;
                }

                char leftChar = s[l];
                if (tMp.count(leftChar)) {
                    sMp[leftChar]--;
                    if (sMp[leftChar] < tMp[leftChar]) {
                        formed--;
                    }
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(resLeft, minLen);
    }
};