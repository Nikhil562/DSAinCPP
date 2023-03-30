class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto i : arr) mp[i]++;
        int mn=n;
        int c=0;
        priority_queue<int> p;
        for(auto i: mp) p.push(i.second);
        
        while(mn>n/2){
            c++;
            mn-=p.top();
            p.pop();
        }
        return c;
    }
};