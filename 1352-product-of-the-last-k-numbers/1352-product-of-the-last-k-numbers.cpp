class ProductOfNumbers {
public:
vector<int> ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int n=ans.size();
        long long cnt=1;
        int i=n-k;
        while(i < n)
        {
           cnt*=ans[i];
           i++;
        }
        return (int)cnt;
    }
};