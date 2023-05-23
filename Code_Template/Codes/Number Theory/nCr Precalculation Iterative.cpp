int ncr[1001][1001];
void calNcr()
{
	ncr[1][1] = 1;
	ncr[1][0] = 1;
	for (int i = 2; i <= n; i++)
	{
		ncr[i][0] = 1;
		ncr[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
		}
	}
}