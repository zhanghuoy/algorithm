#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int minIncrementForUnique(vector<int>& A)
    {
        if (A.size() <= 1)
            return 0;
        sort(A.begin(), A.end());
        int res = 0;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] <= A[i - 1])
            {
                res += A[i - 1] - A[i] + 1;
                A[i] = A[i - 1] + 1;
            }
        }
        return res;
    }
};
//排序后再进行处理即可
/*
此题是典型的数组问题，对于数组问题应该要能够想到排序
排序后发现每次只能递增一个元素，那么就从左往右每次从不递增的位置开始
另外要求最少move次数不是说一次循环就+1，可以一次循环就+n
*/