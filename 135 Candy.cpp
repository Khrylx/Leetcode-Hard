#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int candy(vector<int>& ratings) {
	int res = 1;
	int descend = 0;
	int cur = 1;
	
	for (int i = 1; i < ratings.size(); i++)
	{
		if (ratings[i] >= ratings[i-1])
		{
			if (descend > 0)
			{
				res += (descend + (cur <= 1)) * (1-cur);
				cur = 1;
				descend = 0;
			}
			if (ratings[i] == ratings[i-1])
			{
				cur = 1;
			}
			else
			{
				cur++;
			}
		}
		else if (ratings[i] < ratings[i-1])
		{
			descend++;
			cur--;
		}
		res+=cur;
	}

	res += (descend + (cur <= 1)) * (1-cur);

	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<int> ratings(N);

	for (int i=0; i < N; i++)
	{
		cin >> ratings[i];
	}
	
	int sol = candy(ratings);
	return 1;
}