#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;



int minCut(string s)
{
	int N = s.length();
	vector<int> minC(N+1);
	vector<vector<int>> P(N);

	for (int i = 0; i < N; i++)
	{
		int lb = i-1;
		int ub = i+1;
		while (lb >= 0 && ub < N && s[lb] == s[ub])
		{
			P[ub].push_back(lb);
			lb--;
			ub++;
		}

		lb = i;
		ub = i+1;
		while (lb >= 0 && ub < N && s[lb] == s[ub])
		{
			P[ub].push_back(lb);
			lb--;
			ub++;
		}
	}

	minC[0] = 0;
	minC[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		minC[i] = minC[i-1]+1;
		for (int j = 0; j < P[i-1].size(); j++)
		{
			minC[i] = min(minC[i],minC[P[i-1][j]]+1);
			if (minC[i] == minC[i-1]-1)
				break;
		}
	}

	return minC[N]-1;
}

int main()
{
	int solution = minCut("aab");
	return 1;
}