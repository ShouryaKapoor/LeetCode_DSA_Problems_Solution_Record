class Solution {
public:
long long totalcars(vector<int>&ranks,int cars,long long time){
    int n=ranks.size();
    long long maxcars=0;
    for(int i=0;i<n;i++){
        maxcars +=  sqrt(time/ranks[i]);

    }
    return maxcars;
}











    long long repairCars(vector<int>& ranks, int cars) {
            long long low=1;
            long long high =(long long)*max_element(ranks.begin(),ranks.end())* cars*cars;
            
            while(low<=high){
                long long mid=low+(high-low)/2;
                if(totalcars(ranks,cars,mid)>=cars){
                    
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
              
            }
            return low;
        
    }
};