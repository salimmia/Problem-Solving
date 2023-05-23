/// created by Salim_JnU

#include<bits/stdc++.h>
using namespace std;

#define mx 200005
#define ll long long
#define mod 1000000007 //998244353

int a[mx];
char ch[mx];
int n, m, ii, k;


void solve()
{
    printf("Table:\n");
    printf("---------------------------------------------\n");
    printf("Software Projects  a1    a2   b1    b2\n");
    printf("---------------------------------------------\n");
    printf("Organic            2.4  1.05  2.5  0.38\n");
    printf("Semi Detached      3.0  1.12  2.5  0.35\n");
    printf("Embedded           3.6  1.20  2.5  0.32\n");
    printf("---------------------------------------------\n");

    long double E, D;

    long double o[4] = {2.4, 1.05, 2.5, 0.38};
    long double s[4] = {3.0, 1.12, 2.5, 0.35};
    long double e[4] = {3.6, 1.20, 2.5, 0.32};

    int line, m;
    printf("KLOC: ");
    scanf("%d", &line);
    printf("%d\n", line);
    printf("Organic(1)/Semi Detached(2)/Embedded(3): ");
    scanf("%d", &m);
    printf("%d\n", m);

    if (m == 1) {
        E = o[0] * (pow(line, o[1]));
        D = o[2] * (pow(E, o[3]));
    }

    else if (m == 2) {
        E = s[0] * (pow(line, s[1]));
        D = s[2] * (pow(E, s[3]));
    }
    else {
        E = e[0] * (pow(line, e[1]));
        D = e[2] * (pow(E, e[3]));
    }

    printf("E = %LF\n", E);
    printf("D = %LF\n", D);
    printf("Average staff size = %LF\n", E / D);
    printf("Productivity = %LF\n", line / E);

    return;
}

int main()
{
    int t = 1;
    // scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        // printf("Case %d: ", i);
        solve();
    }
    return 0;
}