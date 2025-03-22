class Solution {
public:
    int id[51], e[51], v[51];
    int root(int x){
        if(x==id[x]) return x;
        return id[x]=root(id[x]);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i=0; i<n; i++) id[i]=i;
        for(int i=0; i<n; i++) e[i]=0;
        for(int i=0; i<n; i++) v[i]=1;
        for(auto &x: edges){
            int a=root(x[0]);
            int b=root(x[1]);
            id[a]=b;
            if(a!=b) v[b]+=v[a];
            if(a!=b) e[b]+=e[a]+1;
            else e[b]++;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(id[i]==i && e[i]==v[i]*(v[i]-1)/2){
                ans++;
            }
        }
        return ans;
    }
};