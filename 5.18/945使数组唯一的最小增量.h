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
//������ٽ��д�����
/*
�����ǵ��͵��������⣬������������Ӧ��Ҫ�ܹ��뵽����
�������ÿ��ֻ�ܵ���һ��Ԫ�أ���ô�ʹ�������ÿ�δӲ�������λ�ÿ�ʼ
����Ҫ������move��������˵һ��ѭ����+1������һ��ѭ����+n
*/