class Solution {
public:
    bool checkValidString(string s) {
        int min_opn=0;
        int max_opn=0;
        for(char c:s){
            if(c=='('){
                min_opn++;
                max_opn++;
            }
            else if(c==')'){
                min_opn--;
                max_opn--;
            }
            else{
                min_opn--;
                max_opn++;
            }
            if(max_opn<0)return false;
            min_opn = max(min_opn, 0);
        }
        return min_opn==0;
    }
};