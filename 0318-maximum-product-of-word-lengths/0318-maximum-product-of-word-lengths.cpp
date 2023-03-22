class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int max1=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            for(char c: words[i]){
                ans[i]|=1<<(c-'a');
            }
            for(int j=0;j<i;j++){
                if(!(ans[i]&ans[j])){
                    if(words[i].size()*words[j].size()>max1){
                        max1=words[i].size()*words[j].size();
                    }
                }
            }
        }
        return max1;
    }
};