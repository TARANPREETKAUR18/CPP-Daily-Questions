class Solution{
public:
    bool canBeValid(string s, string locked){
        int n = s.size();
        if(n % 2 == 1) return false;
        int minOpen = 0, maxOpen = 0;
        for(int i = 0; i < n; i++){
            char c = s[i];
            bool notLocked = locked[i] == '0';
            if(notLocked) minOpen--, maxOpen++;
            else if(c == '(') minOpen++, maxOpen++;
            else if(c == ')') minOpen--, maxOpen--;
            minOpen = max(minOpen, 0);
            if(maxOpen < 0) return false;
        } 
        return minOpen == 0;
    }
};