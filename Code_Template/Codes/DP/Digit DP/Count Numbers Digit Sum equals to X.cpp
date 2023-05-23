Problem
Count the number of integers within the range 
A to B whose digitSum equals to X
(A, B <= 10^9, X <= 10^5)

int dp[11][2][92];//(10^9 has at most 10 digit and sum <= 90)


int func(int pos, int isSmall, int digitSum)
{
    if(pos == 10) return digitSum == X;
    if(dp[pos][isSmall][digitSum] != 1)
    {
    	  return dp[pos][isSmall][digitSum];
    }

    int lo = 0, hi = str[pos] - '0', res = 0;
    if(isSmall) hi = 9;

    for(int i = lo; i <= hi; i++)
    {

    	  int newIsSmall = isSmall | (i < hi);
    	  int val = func(pos + 1, newIsSmall, digitSum + i);

    	  res += val;
    }

    return dp[pos][isSmall][digitSum] = res;
}