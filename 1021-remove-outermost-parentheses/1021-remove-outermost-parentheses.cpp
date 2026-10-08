class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;

        string temp="";

        for(char ch: s){
            if(ch=='(' && count==0){
                count++;
                continue;
            }
            else if(count==1 && ch==')')
            {
                count--;
                continue;
            }else if(ch=='('){
                temp.push_back(ch);
                count++;
            }else{
                temp.push_back(ch);
                count--;
            }
        }
        return temp;
    }
};