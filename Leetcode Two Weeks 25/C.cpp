class Solution {
    bool check(string a,string b){
        for(int i=0;i<a.size();i++){
            if(a[i]<b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkIfCanBreak(string s1, string s2) {
        if(s1==s2) return true;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return check(s1,s2)||check(s2,s1);
    }
};
