class TextEditor{
public:
    stack<char> left, right;
    TextEditor(){
        
    }    
    void addText(string text){
        for(char c:text) left.push(c);
    }    
    int deleteText(int k){
        int cnt=0;
        while(k-- && left.size()){
            left.pop();
            cnt++;
        }
        return cnt;
    }
    string cursorLeft(int k){
        while(k-- && left.size()){
            right.push(left.top());
            left.pop();
        }
        string ans;
        for(int i=0; i<10 && left.size(); i++){
            ans+=left.top();
            left.pop();
        }
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.length(); i++){
            left.push(ans[i]);
        }
        return ans;
    }    
    string cursorRight(int k) {
        while(k-- && right.size()){
            left.push(right.top());
            right.pop();
        }
        string ans;
        for(int i=0; i<10 && left.size(); i++){
            ans+=left.top();
            left.pop();
        }
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.length(); i++){
            left.push(ans[i]);
        }
        return ans;        
    }
};