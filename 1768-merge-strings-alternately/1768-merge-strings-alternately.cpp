class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        string v;
        int i=0;
        int j=0;
        while(i<n && j<m){
            v.push_back(word1[i]);
            v.push_back(word2[j]);
            i++;
            j++;
        }
        while(i<n){
            v.push_back(word1[i]);
            i++;
        }
        while(j<m){
            v.push_back(word2[j]);
            j++;
        }
        return v;
        
    }
};