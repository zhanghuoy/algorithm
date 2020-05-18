#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        //每次都把所有橘子都遍历一遍
        int res = 0, flag = 0;
        vector<vector<int>> pos = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        while (1)
        {
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (grid[i][j] == 2+res)
                    {
                        for (int k = 0; k < pos.size(); k++)
                        {
                            int x = i + pos[k][0], y = j + pos[k][1];
                            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[i].size() && grid[x][y] == 1)
                            {
                                flag = 1;
                                grid[x][y] = res + 2 + 1;
                            }
                        }
                        grid[i][j] = -1;
                    }
                }
            }
            if (flag)
                res++;
            else
                break;
            flag = 0;
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return res;
    }
};
//图的广度优先搜索问题