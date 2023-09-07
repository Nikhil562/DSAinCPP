class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>> q;
        unordered_map<int,int> mp;
        for(auto i: barcodes) mp[i]++;
        for(auto i: mp) q.push({i.second,i.first});
        if(barcodes.size()==1) return barcodes;
        vector<int> ans;
        while(q.size()>1){
            int firstF=q.top().first;
            int firstEl=q.top().second;
            q.pop();
            
            int secondF=q.top().first;
            int secondEl=q.top().second;
            q.pop();
            
            firstF--;
            if(firstF!=0) q.push({firstF,firstEl});
            secondF--;
            if(secondF!=0) q.push({secondF,secondEl});
            ans.push_back(firstEl);
            ans.push_back(secondEl);
        }
        if(q.size()>0){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};