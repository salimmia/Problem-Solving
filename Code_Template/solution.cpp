// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007 //998244353


///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


void solve()
{
    int n;
    cin >> n;

    ll Pr[2 * n + 5], Pi[2 * n + 5];

    int idx_max = -1;
    int idx_min = -1;

    bool ok = false;

    ll mx = -1;
    ll mn = 1e15;

    ll MIN = mn;

    for (int i = 1; i <= n; i++)
    {
        cin >> Pr[i] >> Pi[i];
    }

    for (int i = n + 1; i <= 2 * n; i++)
    {
        Pr[i] = Pr[i - n];
        Pi[i] = Pi[i - n];
    }

    Pr[0] = Pr[n];
    Pi[0] = Pi[n];

    // for (int i = 0; i <= 2 * n; i++)
    // {
    //     watch3(i, Pr[i], Pi[i]);
    // }

    for (int i = 1; i <= n; i++)
    {
        ll extra = Pi[i] - Pr[i];

        ll prev_extra = Pi[i - 1] - Pr[i - 1];

        prev_extra = max(0ll, prev_extra);

        extra += prev_extra;

        //watch2(i, extra);



        if (extra > mx)
        {
            mx = extra;
            idx_max = i;
        }

        if (extra < mn)
        {
            mn = extra;
            idx_min = i;
        }

        /*else if(Pi[i] - Pr[i] == mx)
        {
            if(Pr[i] < choto)
            {
                mx = Pi[i] - Pr[i];
                idx = i;
                choto = Pr[i];
            }
        }*/
    }





    if (idx_max == -1)
    {
        cout << "NO" << endl;
        return;
    }

    //watch(idx_max);


    // for (int i = 0; i <= 2 * n; i++)
    // {
    //     watch3(i, Pr[i], Pi[i]);
    // }




    //checking max

    int last = idx_max - 1;

    ll prev = max(0ll, Pi[last] - Pr[last]);


    bool mx_check = true;

    //watch(prev);


    for (int i = idx_max; i < idx_max + n; i++)
    {
        //watch3(prev, Pr[i], Pi[i]);
        if (Pr[i] - prev > Pi[i])
        {
            mx_check = false;
            break;
        }



        //Pi[i] -= Pr[i];

        prev = max(0ll, Pi[i] - max(0ll, Pr[i] - prev));
    }

    if (mx_check) ok = true;

    if (ok)
    {
        cout << "YES" << endl;
        return;
    }

    // Min checking.......


    last = idx_min;

    prev = max(0ll, Pi[last] - Pr[last]);


    mx_check = true;

    //watch2(prev, idx_min);


    for (int i = idx_min + 1; i < idx_min + 1 + n; i++)
    {
        //watch2(i, prev);
        //watch3(i, Pr[i], Pi[i]);

        //Pr[i] -= prev;
        //Pr[i] = max(0ll, Pr[i]);
        //watch2(Pr[i], Pi[i]);

        if (Pr[i] - prev > Pi[i])
        {
            mx_check = false;
            break;
        }



        //Pi[i] -= Pr[i];

        prev = max(0ll, Pi[i] - max(0ll, Pr[i] - prev));
    }

    if (mx_check) ok = true;

    if (ok)
    {
        cout << "YES" << endl;
        return;
    }


    cout << "NO" << endl;

    return;


}

int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)solve();
    return 0;
}