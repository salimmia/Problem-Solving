#define mxn 100005

int a[mxn], actual[mxn];


int num = 1;

for(int i = 0; i < n; i++)
{
    cin>>a[i];
    if(mp.find(a[i]) == mp.end())
    {
        actual[i] = a[i];

        mp[a[i]] = num;
        a[i] = num;
        num++;
    }
    else
    {
        actual[i] = a[i];
        a[i] = mp[a[i]];
    }

}

My Problem Submission That used this Technique...
https://codeforces.com/contest/220/submission/127141731