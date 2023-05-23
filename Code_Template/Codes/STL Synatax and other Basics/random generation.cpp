#include <bits/stdc++.h>
 
using namespace std;
const int N = 3000000;

//C++ rand() functions mx value is approximately 32767
// rng() functions mx value 10^18\
// TC : O(1) for both function


//This line takes the time of our computer nano second level
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// MUST ADD

 
double average_distance(const vector<int> &permutation)
{
    double distance_sum = 0;
 
    for (int i = 0; i < N; i++)
        distance_sum += abs(permutation[i] - i);
 
    return distance_sum / N;
}
 
int getRandom(int L,int R) /// generate random numbers in range [L,R]
{
    return rng()%(R-L+1) + L;
}
ll my_rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r) (rng);
}



int main()
{
    int numb = rng(); /// use rng() to generate random numbers.
    cout << numb << "\n";
 
    vector<int>permutation(N);
 
    for (int i = 0; i < N; i++)
        permutation[i] = i;
 
    shuffle(permutation.begin(), permutation.end(), rng); /// you can random_shuffle a vector with this function.
    cout << average_distance(permutation) << '\n';
 
    return 0;
}