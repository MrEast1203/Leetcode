#include <iostream>
#include <vector>
using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> LCS[nums1.size() + 1];
    int maxi=0;
    for (int i = 0; i <= nums1.size(); i++)
    {
        LCS[i].push_back(0);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        LCS[0].push_back(0);
    }
    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j <= nums2.size(); j++)
        {
            if (nums1[i-1] == nums2[j-1])
            {
                LCS[i].push_back(LCS[i - 1][j - 1]+1);
                maxi=max(maxi, LCS[i - 1][j - 1]+1);
            }
            else
            {
                LCS[i].push_back(0);
            }
        }
    }
    return maxi;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    int ans = findLength(nums1, nums2);
    cout << ans << endl;
    return 0;
}
