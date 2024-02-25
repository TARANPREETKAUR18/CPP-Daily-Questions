class Solution{
public:
    int misDistanceMain(string &word1, string &word2, int indexOfWord1, int indexOfWord2, vector<vector<int>> &cache){
        //base case: word1 or word2 has been traversed
        if(!indexOfWord1 || !indexOfWord2)
            return indexOfWord1 > indexOfWord2 ? indexOfWord1: indexOfWord2;
        
        if(cache[indexOfWord1-1][indexOfWord2-1]!=-1) return cache[indexOfWord1-1][indexOfWord2-1];
        
        //recursive call
        if(word1[indexOfWord1-1]==word2[indexOfWord2-1])
            return cache[indexOfWord1-1][indexOfWord2-1] = misDistanceMain(word1, word2, indexOfWord1-1, indexOfWord2-1, cache);
        
        //return statement
        return cache[indexOfWord1-1][indexOfWord2-1] = min(misDistanceMain(word1, word2, indexOfWord1-1, indexOfWord2-1, cache), min(misDistanceMain(word1, word2, indexOfWord1, indexOfWord2-1, cache), misDistanceMain(word1, word2, indexOfWord1-1, indexOfWord2, cache)))+1;
    }
    int minDistance(string word1, string word2){
        vector<vector<int>> cache(word1.size(), vector<int>(word2.size(), -1));
        return misDistanceMain(word1, word2, word1.size(), word2.size(), cache);
    }
};