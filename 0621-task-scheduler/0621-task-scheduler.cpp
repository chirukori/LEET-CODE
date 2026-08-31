class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int> count(26, 0);
        vector<int> nextValidTime(26, 0); 
        for (char task : tasks) {
            count[task - 'A']++;
        }
        int time = 0;
        int totalTasks = tasks.size();
        while (totalTasks > 0) {
            int bestTask = -1;
            int maxCount = 0;
            for (int i = 0; i < 26; i++) {
                 
                if (count[i] > 0 && time >= nextValidTime[i]) {
                    if (count[i] > maxCount) {
                        maxCount = count[i];
                        bestTask = i;
                    }
                }
            }
            if (bestTask != -1) {
              
                count[bestTask]--;
                nextValidTime[bestTask] = time + n + 1; 
                totalTasks--;
            }
            time++;  
        }
        return time;
    }
};