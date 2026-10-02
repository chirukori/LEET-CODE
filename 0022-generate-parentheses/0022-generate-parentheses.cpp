class Solution {
public:
        vector<string>ans;
        void backtrack(int n,string current ,int open,int closed){
            for(int i=0;i<2;i++){
                if(current.length()==2*n){
                    ans.push_back(current);
                    return;
                }
            if(i==0){
                if(open<n){
                current.push_back('(');
                backtrack(n,current,open+1,closed);
                current.pop_back();
                }
            }
            else{
                 if(closed<open){
                current.push_back(')');
                backtrack(n,current,open,closed+1);
                current.pop_back();
                }
            }
        }
        }
        vector<string> generateParenthesis(int n) {
            string current;
            backtrack(n,current,0,0);
            return ans;
        
        }
};