/*
 Programmer : Anamaria Andra Pescaru 
 Link to the problem : https://www.codechef.com/START11C/problems/FACEDIR
*/
#include<bits/stdc++.h>
using namespace std;
// ifstream fcin("input.txt");
// ofstream fcout("output.txt");
// #define cin fcin
// #define cout fcout

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cout<<fixed<<setprecision(15);

    int test;
    cin>>test;

    while(test--){
        int x;
        cin>>x;
        if(x % 4 == 0)
        cout<<"North\n";
        if(x % 4 == 1)
        cout<<"East\n";
        if(x % 4 == 2)
        cout<<"South\n";
        if(x % 4 == 3)
        cout<<"West\n";
    }

	return 0;
}
