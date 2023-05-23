#include<bits/stdc++.h>
using namespace std;

#define sz 100000
int main()
{
    /**Array Related**/

    ///Fill by certain number
    int arr[sz];
    fill(arr,arr+10,-2);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    ///Finding max/min element of an array
    arr[100]=INT_MAX;
    arr[200]=INT_MIN;
    cout<<*max_element(arr,arr+sz)<<endl;
    cout<<*min_element(arr,arr+sz)<<endl;



    return 0;
}


