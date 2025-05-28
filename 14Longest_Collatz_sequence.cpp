#include <bits/stdc++.h>
#include<vector>
using namespace std;

int target = 5000001;
vector<long> arr(target, 0);
    
long countchain(long num)
{
    if(arr[num]!=0) return arr[num];
    if(num%2==0) arr[num]=1+countchain(num/2);
    else {
        long temp=0, count=1;
        temp=num*3+1;
        while(temp>target)
        {
            if(temp%2==0) temp/=2;
            else temp=temp*3+1;
            count++;
        }
        arr[num]=count+countchain(temp);
    }
    return arr[num];
}
int main()
{
        long cas, item;
        arr[1]=1;
        for(long a=1;a<=target;a++)
        {
            countchain(a);
        }
        vector<long> results(target);
        results[1] = 1;
        for(long a=1;a<=target;a++)
        {
            if(arr[a] >= arr[results[a-1]]) results[a] = a;
            else results[a] = results[a-1];
        }
        
        cin >> cas;
        for(int c = 0; c < cas; c++) {
            cin >> item;
            cout << results[item] << endl;
        }
        
        return 0;
}