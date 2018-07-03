/// Coin number is unlimited
/// Check if we can make value 'make' using the coin
#include<bits/stdc++.h>
using namespace std;

int dp[100][1000], coin[100], make, n;
int call(int i, int amount)
{
    if(i>n){            /// All coins have been taken
        if(amount==make)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    int ret1=0, ret2=0;
    if(amount+coin[i]<=make) ret1 = call(i, amount+coin[i]);/// As coin number is unlimited, again taking ith coin
    ret2 = call(i+1, amount);                               /// not taking ith coin
    return dp[i][amount] = ret1 | ret2;
}

int main()
{
    cout<<"Please Enter the number of coin: ";
    cin>>n;
    cout<<"Now Enter the coin value: ";
    for(int i=1;i<=n;i++)
        cin>>coin[i];

    while(1)
    {
        cout<<"Enter the value which you want to make using coin: ";
        cin>>make;

        memset(dp, -1, sizeof(dp));

        int res = call(1, 0);

        if(res)
            cout<<make<<" can be made using the coin"<<endl;
        else
            cout<<make<<" can not be made using the coin"<<endl;
    }

    return 0;
}
