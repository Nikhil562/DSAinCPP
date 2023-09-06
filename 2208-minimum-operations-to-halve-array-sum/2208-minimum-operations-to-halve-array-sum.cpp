class Solution {
public:

    int halveArray(vector<int>& nums) 
    {
        // use priority Queue to store elements in assending order
        // So Biggest element is always on top of Queue
        priority_queue<double>Q;

        double sum=0;   //Total sum of element

        //store all elments in Queue
        for(auto ele : nums)
        {
            sum+=ele;
            Q.push(ele);
            
        }
        
        //half of total
        double half=sum/2;

        //count operations until sum is greater than half 
        int count=0;
        while(sum>half)
        { 
            double max=Q.top();     //maximum emement of Queue
            Q.pop();                //remove it from Queue

            max/=2;                 
            Q.push(max);            //add half of that element
            count++;                //count accurance of operation

            sum-=max;               //substarct half of element from sum 
        }
       
        return count;
        
    }
};