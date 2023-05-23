#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

int arr[MAX + 5];
const int block_s = 320;

struct Query
{
    int l, r, id;
    bool operator<(const Query &oth)const
    {
        int b_a = l / block_s;
        int b_b = oth.l / block_s;
        if(b_a == b_b) return r < oth.r;
        return b_a < b_b;
    }
};

int unique_values, L, R, ans[MAX + 5], freq[MAX + 5];
Query queries[MAX + 5];

void add(int idx)
{
    freq[arr[idx]]++;
    if(freq[arr[idx]] == 1) unique_values++;
}

void remov(int idx)
{
    freq[arr[idx]]--;
    if(freq[arr[idx]] == 0) unique_values--;
}

int main()
{
    int n, Q, T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &Q);

        unique_values = 0;
        memset(freq, 0, sizeof freq);
        L = 0;
        R = -1;
        // block_s = sqrt(n) + 1;

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for(int i = 0; i < Q; i++)
        {
            scanf("%d%d", &queries[i].l, &queries[i].r);
            --queries[i].l;
            --queries[i].r;
            queries[i].id = i;
        }
        sort(queries, queries + Q);
        for(int i = 0; i < Q; i++)
        {
            while(queries[i].l < L) add(--L);
            while(queries[i].l > L) remov(L++);
            while(queries[i].r < R) remov(R--);
            while(queries[i].r > R) add(++R);
            ans[queries[i].id] = unique_values;
        }
        printf("Case %d:\n", cs++);
        for(int i = 0; i < Q; i++)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}