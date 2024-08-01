
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
2
7
11
15


mp = {
    3: "0",
    2: "1",
    4: "2",
}

3
neededTarget = 6 - 3 = 3 available in map no



*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int currentElement = nums[i];
            int neededElement = target - currentElement;
            if (mp.find(neededElement) != mp.end())
            {
                return vector<int>{mp[neededElement], i};
            }
            mp[currentElement] = i;
        }
        return vector<int>{1, 1};
    }

    // 2 3 4 => 6
    vector<int> twoSumUsingGreedyPointerApproach(vector<int> &nums, int target)
    {
        int firstPointer = 0;
        int lastPointer = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (firstPointer < lastPointer)
        {
            int sum = nums[firstPointer] + nums[lastPointer];
            if (sum == target)
            {
                return vector<int>{firstPointer, lastPointer};
            }
            if (target > sum)
                firstPointer++;
            else if (target < nums[firstPointer] + nums[lastPointer])
            {
                lastPointer--;
            }
        }

        return vector<int>{-1, -1};
    }
};

int main(void)
{
    Solution s;
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> ans = s.twoSumUsingGreedyPointerApproach(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}