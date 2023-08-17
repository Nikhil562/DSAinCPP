class Solution {
public:
    // bool compare(string s1, string s2){
    //     int i=0,j=0;
    //     int n=s1.size(),m=s2.size();
    //     while(i<n){
    //         if(s1[i]==s2[j] && j<m) {
    //             i++;
    //             j++;
    //         }else i++;
    //     }
    //     return (i==n && j==m);
    // }
    // static bool comp(string s1, string s2){
    //     return s1.size()<s2.size();
    // }
    // int longestStrChain(vector<string>& words) {
    //     int n=words.size();
    //     vector<int> dp(n,1);
    //     sort(words.begin(),words.end(),comp);
    //     int maxi=1;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<i;j++){
    //             if(compare(words[i],words[j]) && 1+dp[j]>dp[i]){
    //                   dp[i]=1+dp[j];                  
    //               }   
    //     }
    //         maxi=max(maxi,dp[i]);
    //     }
    //     return maxi;
    // }
    bool compare(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}
static bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string>& arr){
    int n = arr.size();
    
    //sort the array
    
    sort(arr.begin(), arr.end(),comp);
    vector<int> dp(n,1);
    
    int maxi = 1;
    
    for(int i=0; i<=n-1; i++){
        
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if( compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
            }
        }
        
        if(dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}
    
};