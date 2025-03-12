class Solution
{
public:
    int numberOfSubstrings(string s) 
    {
       int n=s.size();
       int l=0;
       int ans=0;
       map<char,int>mp;
       for(int r=0;r<n;r++)
       {
          mp[s[r]]++;
          while(mp['a']>0 && mp['b']>0 && mp['c']>0 && l<n)
          {
             ans+=(n-r);
            // cout<<ans<<" ";
             mp[s[l]]--;
             l++;
          }  
       }
       return ans;
    }
};