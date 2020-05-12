class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len = candies.size();
        int ma =0;
        vector<bool> ans(len,false);
        for(int i=0;i<len;i++) ma = max(ma,candies[i]);
        for(int i=0;i<len;i++){
            int tt = candies[i]+extraCandies;
            if(tt>=ma) ans[i] = true;
        }
        return ans;
    }
};
