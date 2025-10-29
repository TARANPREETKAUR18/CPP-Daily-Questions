class Solution {
public:
    bool isPalindrome(long long x) {
        if(x<0) return false;
        long long temp = 0;
        long long num = x;
        while(x!=0){
            temp = temp*10 + x%10;
            x = x/10;
        }
        return temp==num;
    }
};