

#include<iostream>
using namespace std;
 
    int main()
 
    {
 
        int n,k;
 
        cin>>n>>k;
 
        int s = 0;
 
        for(int i =2;i<=n;++i)
 
        s+=(s+k)%i;
 
        cout<<s+1<<endl;
 
        return 0;
 
    }
