#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    ll a,b;
    cin>>a>>b;



    ///two numbers
    ///works for ll also.....
    cout<<__gcd(a,b)<<endl;
    cout<<gcd(a,b)<<endl;

    /// n numbers

    int n; cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    ll g = 0;
    for(int i=0;i<n;i++)
    {
        g = __gcd(g,arr[i]);
    }

    cout<<g<<endl;

    /// a * b = gcd * lcm
}


*** Lcm of n numbers 
#include <stdio.h>
int findGCD(int, int);

int main() {
    int array[] = {8, 4, 2, 16};
    int lcm = array[0];;
    int  gcd = array[0];
 
    //Loop through the array and find GCD
    //use GCD to find the LCM
    for(int i=1; i<4; i++){
      gcd = findGCD(array[i], lcm);
      lcm = (lcm*array[i])/gcd;
    }
    
    printf("LCM: %d", lcm);
}

//Function returns GCD of a and b
int findGCD(int a, int b){
    if(b==0)
        return a;
    return findGCD(b, a%b);
}