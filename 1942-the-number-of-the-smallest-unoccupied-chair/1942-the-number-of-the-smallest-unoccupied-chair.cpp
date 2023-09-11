class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tf) {
        
        int n=times.size();
        
        //Making 2-D array so that after sorting index of element remain same 
        vector<vector<int>>arr(n,vector<int>(3,0));
        
        for(int i=0;i<times.size();i++){
            arr[i]={times[i][0],times[i][1],i};
        }
        
        sort(arr.begin(), arr.end());
         
        //Min heap holds the leaving time and no. of chair 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
        set<int>s;
        
        int num=-1;
        for(int i=0;i<n;i++){
        
            while(!pq.empty() and pq.top().first<=arr[i][0]){
                s.insert(pq.top().second);
                pq.pop();
            }
            
            if(s.size()>0){
                int chairNo = *s.begin();
                s.erase(s.begin());
                pq.push({arr[i][1],chairNo});
                if(arr[i][2]==tf)return chairNo;
                
            }
            
            else{
                num++;
                pq.push({arr[i][1],num});
                if(arr[i][2]==tf)return num;
            }
            
            
        }
        
        return 0;
        
         // Run this test case for more visualisation  [[1,3],[2,5],[3,6],[6,7]]

    }
};