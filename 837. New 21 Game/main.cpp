#include<iostream>
#include<vector>
using namespace std;
double new21Game(int n, int k, int maxPts) {
    double dp[n+maxPts+1];
    for(int i=0;i<=n+maxPts;i++){
        dp[i]=0;
    }
    for(int i=k;i<=n;i++){
        dp[i]=1.0;
    }
    double S=min(n-k+1,maxPts);
    for(int i=k-1;i>=0;i--){
        dp[i]=S/maxPts;
        S+=(dp[i]-dp[i+maxPts]);
    }
    return dp[0];

}
int main(){
    int n=421;
    int k=400;
    int maxPts=47;
    cout<< new21Game(n, k, maxPts) << endl;
    return 0;
}