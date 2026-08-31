class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
 
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
 
        for (auto const& [card, freq] : count) {
            if (freq > 0) {
                int startCount = freq;
                for (int i = 0; i < groupSize; ++i) {
                    if (count[card + i] < startCount) {
                        return false;
                    }
                    count[card + i] -= startCount;
                }
            }
        }

        return true;
    }
};