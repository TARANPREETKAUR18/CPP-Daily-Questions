class Solution{
public:
    bool checkValidString(string s){
        int minOpen = 0, maxOpen = 0;
        for(auto it : s){
            if (it == '('){
                minOpen++;
                maxOpen++;
            }
            else if(it == ')'){
                minOpen = max(0, minOpen - 1);
                maxOpen--;
            }
            else{
                minOpen = max(0, minOpen - 1);
                maxOpen++;
            }
            if (maxOpen < 0) return false;
        }
        return minOpen == 0;
    }
};