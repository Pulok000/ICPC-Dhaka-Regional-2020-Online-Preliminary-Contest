//A. AB Balance

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define deb(x) cout<<#x<<" "<<x<<endl;

#define pb push_back
#define mp make_pair
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define test() cout<<"test-"<<c++<<endl;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void printV(vector<int> v);
void printS(set<int> s);


int charToInt(char c);
char intToChar(int x);


string numSpliteToString(int n){
    
    int r;
    string s;

    while(n!=0)
    {
        r=n%10;
        n=n/10;
        s.push_back(r);
    }

    reverse(s.begin(),s.end());

    return s;
}



void solve(ll testcase)
{
    

    bool neg=false,allneg=true;

    ll n,sum=0;

    cin>>n;

    vector<ll> v(n);


    for(ll i=0;i<n;i++){

        cin>>v[i];


        if(v[i]>0){
           sum+=v[i];
        }
        

        if(v[i]<0)
            neg=true;

        if(v[i]>0){
            allneg=false;
        }


            

    }



    if(!neg){
        // cout<<"test case: "<<testcase<<" All positive"<<endl;

        cout<<"Case "<<testcase<<": "<<sum<<" "<<"0"<<endl;
    }
    else if(allneg){

        // cout<<"test case: "<<testcase<<" all negative"<<endl;

        ll small=v[0];

        for(ll i=0;i<n;i++){
            if(small<v[i]){
                small=v[i];
            }
        }
        cout<<"Case "<<testcase<<": "<<small<<" "<<"0"<<endl;

    }
    else{

        // cout<<"test case: "<<testcase<<" Mix"<<endl;


        ll start,end;

        for(ll i=0;i<n;i++){
            if(v[i]>0){
                start=i;
                break;
            }
        }


        for(ll i=n-1;i>=0;i--){

            if(v[i]>0){
                end=i;
                break;
            }

        }

        bool on=false,pos=false;

        ll ct=0;

        for(ll i=start;i<=end;i++){

            if(v[i]>0){
                pos=true;
            }

            if(pos==true && v[i]<0){
                on=true;
            }
            else if(on==true && v[i]>0){
                ct++;
                on=false;
            }

        }
        // deb(sum)

        cout<<"Case "<<testcase<<": "<<sum<<" "<<ct<<endl;

    }




}

int main()
{
optimize();


// #ifndef ONLINE_JUDGE

//    // For getting input from input.txt file
//    freopen("C:\\Users\\admin\\Desktop\\input Output\\input.txt", "r", stdin);

//    // Printing the Output to output.txt file
//    freopen("C:\\Users\\admin\\Desktop\\input Output\\output.txt", "w", stdout);

// #endif



    //ll t;
    ll t,testcase=0;
    cin>>t;

    while(t--)
    {
        //cout<<solve()<<endl;
        testcase++;

        solve(testcase);
    }

    return 0;
}


void printV(vector<int> v)
{
    for(auto i=v.begin(); i!=v.end(); i++)
    {
        cout<<*i<<endl;
    }
}

void printS(set<int> s)
{
    for(auto i=s.begin(); i!=s.end(); i++)
    {
        cout<<*i<<endl;
    }
}


int charToInt(char c){

 //char a = c;
 int num = c-'0';

 return num;

}

char intToChar(int x){

    //int i = x;
    char c = '0'+x;

    return c;
}
