class Solution {
public:
    bool isPalindrome(int x) {
        string st = to_string(x);
        int start=0, end=st.size()-1;
        if(x<0 || (x!=0 && x%10==0)){
            return false;
        }
        while(start<=end){
            if(st[start]!=st[end]){
                return false;
            }
            start++,end--;
        }
        return true;
    }
};