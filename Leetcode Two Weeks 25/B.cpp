class Solution {
public:
    int maxDiff(int num) {
        string x = to_string(num);
        int ma =0;
        int mi = 1e9;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                if((x[0]-'0')==i&&j==0) continue;
                if(i==j) continue;
                string tmp = x;
                for(int k=0;k<tmp.size();k++){
                    if((tmp[k]-'0') == i){
                        tmp[k] = j+'0';
                    }
                }
                int tt = stoi(tmp);
                if(tt==0) continue;
                ma = max(ma,tt);
                mi = min(mi,tt);
            }
        }
        return ma -mi;
    }
};
