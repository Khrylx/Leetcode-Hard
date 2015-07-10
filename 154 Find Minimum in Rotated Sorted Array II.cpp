#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findMin(vector<int>& nums) 
{
	int left = 0;
	int right = (int)nums.size()-1;
	if (right == 0)
		return nums[0];

	if (nums[left] < nums[right])
	{
		return nums[left];
	}
	if (nums[right-1] > nums[right])
	{
		return nums[right];
	}

	while (1)
	{
		if (left == right)
		{
			return nums[left];
		}
		int newPos = (left+right)/2;
		if (newPos > 0 && nums[newPos] < nums[newPos-1])
		{
			return nums[newPos];
		}
		if (nums[newPos] > nums[newPos+1])
		{
			return nums[newPos+1];
		}
		if (nums[left] == nums[right] && nums[left] == nums[newPos])
		{
			int posRec = newPos;
			newPos++;
			while (newPos < right && nums[newPos] == nums[left])
			{
				newPos++;
			}
			if (newPos == right)
			{
				right = posRec;
			}
			else if(nums[newPos] < nums[newPos-1])
			{
				return nums[newPos];
			}
			else
			{
				left = posRec;
			}
		}
		else
		{
			if (nums[newPos] < nums[left])
			{
				right = newPos;
			}
			else
			{
				left = newPos;
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	int res = findMin(nums);
	return 1;
}