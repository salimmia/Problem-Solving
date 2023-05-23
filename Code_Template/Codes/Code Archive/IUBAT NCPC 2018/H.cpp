#include<bits/stdc++.h>
using namespace std;


///typedef
typedef long long ll;
typedef pair<int, int> pii;

///define constant
const ll mxn = 200005;
const int mod = 1000000007;//1e9+7;

///faster io
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///debug
#define watch(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define watch2(x,y) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<endl
#define watch3(x,y,z) cout<< __LINE__ << " says: " <<#x<<" = "<<x<<" "<<#y<<" = "<<y <<" "<<#z<<" = "<<z<<endl


///program starts...........




void solve_case(int tc)
{
    string s;
    cin>>s;

    int t;
    cin>>t;

    int point = -1;

    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if(ch == '.')
        {
            point = i;
            break;
        }
    }


    if(point + t + 1 < s.size())
    {
        if(s[point + t + 1] >= '5')
        {
            s[point + t] = (s[point + t] + 1);
        }
    }

    bool started = false;

    for(int i = 0; i < point; i++)
    {
        if(started)
        {
            cout<<s[i];
        }
        else 
        {
            if(s[i] > '0')
            {
                cout<<s[i];
                started = true;
            }
            else
            {
                if(i == point - 1)
                {
                    cout<<s[i];
                }
            }
        }
    }

    cout<<s[point];

    for(int i = point + 1; i <= point + t; i++)
    {
        if(i < s.size())
        {
            cout<<s[i];
        }
        else cout<<0;
    }

    cout<<endl;



    return;
}

int main()
{
    faster_io;

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int test_case=1;
    cin>>test_case;
    for(int tc=1 ; tc<=test_case; tc++)
    {
        solve_case(tc);
    }
///  KeyPoint


///  Corner Cases




    return 0;
}


