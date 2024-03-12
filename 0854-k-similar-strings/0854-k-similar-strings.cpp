class Solution{
public:
    string str_;
    string_view target_;
    int backtrack(int from) {
        while(from != str_.size() && str_[from] == target_[from]) ++from;
        if(from == str_.size()) return 0;
        for(int to = from + 1; to != str_.size(); ++to) {
            if (str_[to] != target_[from] || str_[from] != target_[to]) continue;
            swap(str_[from], str_[to]);
            int result = 1 + backtrack(from + 1);
            swap(str_[from], str_[to]);
            return result;
        }
        int result = INT_MAX;
        for(int to = from + 1; to != str_.size(); ++to){
            if (str_[to] != target_[from] || str_[to] == target_[to]) continue;
            swap(str_[from], str_[to]);
            result = min(result, 1 + backtrack(from + 1));
            swap(str_[from], str_[to]);
        }
        return result;
    }
    int kSimilarity(string& s1, string_view s2){
        str_ = move(s1);
        target_ = s2;
        return backtrack(0);    
    }
};