1425. 带限制的子序列和
给你一个整数数组 nums 和一个整数 k ，请你返回 非空 子序列元素和的最大值，子序列需要满足：子序列中每两个 相邻 的整数 nums[i] 和 nums[j] 
，它们在原数组中的下标 i 和 j 满足 i < j 且 j - i <= k 。

数组的子序列定义为：将数组中的若干个数字删除（可以删除 0 个数字），剩下的数字按照原本的顺序排布。
示例 1：

输入：nums = [10,2,-10,5,20], k = 2
输出：37
解释：子序列为 [10, 2, 5, 20] 。


1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

Solve：设dp[i] 表示以i结尾的最大的序列和
则 ans = max(ans,dp[i]) 
dp[i] = max(max(dp[i-1],dp[i-1],dp[i-2],...dp[i-k])+nums[i],nums[i]);
那么可以用单调队列维护最大的j ~ i &&i-j<=k的最大dp的值

代码如下：

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int len = nums.size();
        int ans=nums[0];
        vector<int> dp(len+10,0);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for(int i=1;i<len;i++){
            dp[i] = max(dp[dq.front()]+nums[i],nums[i]);
            ans = max(ans,dp[i]);
            if(i-dq.front()>=k) dq.pop_front();
            while(!dq.empty()&&dp[dq.back()]<dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return ans;
    }
};
