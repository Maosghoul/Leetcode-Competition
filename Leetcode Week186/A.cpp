class Solution {
public:
    int maxScore(string s) {
        int ma=0;
        int len = s.size();
        if(len==0) return ma;
        for(int i=1;i<=len-1;i++){
            int left=0,right=0;
            string ll = s.substr(0,i);
            string rr = s.substr(i);
            for(int j=0;j<ll.size();j++) left+=ll[j]=='0';
            for(int j=0;j<rr.size();j++) right+=rr[j]=='1';
            ma = max(ma,left+right);
        }
        return ma;
    }
};
