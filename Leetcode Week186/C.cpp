const int maxn = 1e5+5;
class Solution {
public:
    vector<int> a[maxn];
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();

        int ma =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                a[i+j].push_back(nums[i][j]);
                ma = max(ma,i+j);
            }
        }
        vector<int> ans;
        for(int j=0;j<=ma;j++){
            for(int k=a[j].size()-1;k>=0;k--){
                ans.push_back(a[j][k]);
            }
        }
        return ans;
    }
};
