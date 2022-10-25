#include <iostream>
#include <vector>
using namespace std;
bool PredictTheWinner(vector<int> &nums)
{
    if(nums.size()<=2){
        return true;
    }
    int n=nums.size();
    int arr[n][n];
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            arr[i][j]=0;
        }
    }
    for(int k=nums.size();k>=0;k--){
        for(int h=k;h<nums.size();h++){
            if(h==k){
                arr[k][h] = nums[k];
            }
            else{
                arr[k][h]=max(nums[k] - arr[k + 1][h],nums[h] - arr[k][h - 1]);
            }
        }
    }
    int a=arr[0][nums.size()-1]>=0;
    return (arr[0][nums.size()-1]>=0);
}

int main()
{
    vector<int> nums = {1,5,2,4,6};
    cout << PredictTheWinner(nums) << endl;
    return 0;
}