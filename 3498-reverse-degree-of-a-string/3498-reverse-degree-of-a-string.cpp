class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            int alphabet=ch-'a'+1;
            int reverse=27-alphabet;
            int position=i+1;
            int product=reverse*position;
            sum+=product;
        }
        return sum;
    }
};