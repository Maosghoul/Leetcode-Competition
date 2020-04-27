class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        vector<int> a;
        for(int i=0;i<len;i++) a.push_back(cardPoints[i]);
        for(int i=0;i<len;i++) a.push_back(cardPoints[i]);
        int sum=0;
        for(int i=len-k;i<len;i++) sum+=a[i];
        int ma = sum;
        for(int i=len;i<=len+k-1;i++){
            sum-=a[i-k];
            sum+=a[i];
            ma = max(ma,sum);
        }
        return ma;
    }
};
