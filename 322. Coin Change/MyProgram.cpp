#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    int dp[++amount];
    dp[0]=0;
    sort(begin(coins), end(coins));
    for(int i=1;i<=amount;i++){
        dp[i]=INT_MAX;
    }
    for(int i=1;i<=amount;i++){
        for(int c:coins){
            if(i-c<0){break;}
            if(dp[i-c]!=INT_MAX){
                dp[i]=min(dp[i], 1+dp[i-c]);
            }
        }
    }
    if(dp[amount]!=INT_MAX){
        return dp[amount];
    }
    else{
        return -1;
    }
}

int main(){
    vector<int> coins={474,83,404,3};
    int amount=264;
    cout<<coinChange(coins, amount)<<endl;
    return 0;
}