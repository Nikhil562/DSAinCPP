class Solution {
public:
    typedef pair<int,int> pr;
    // int maximumSum(vector<int>& nums) {
    int maximumSum(vector<int>& nums) {
    priority_queue<pr,vector<pr>,greater<pr>>q;
    for(int i:nums){
        int temp =i;
        int sum = 0;
        while(temp!=0){
            sum +=temp%10;
            temp=temp/10;
        }
        q.push({sum,i});
    }
    int res =-1;
    auto x = q.top();
        int sum = x.first;
        int value = x.second;
        q.pop();
    while(q.empty()==false){
        
        if(sum == q.top().first){
            res = max(res,value+q.top().second);
        }
        sum = q.top().first;
        value = q.top().second;
        q.pop();
    }
    return res;
}
    
};