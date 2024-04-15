//__________Includes__________________//
 
# include               <iostream>
# include               <algorithm>
# include               <vector>
# include               <string>
# include               <map>
# include               <unordered_map>
# include               <set>
# include               <unordered_set>
# include               <bitset>
# include               <queue>
# include               <stack>
# include               <complex>
# include               <cmath>
# include               <climits>
# include               <cstring>
 
//____________Containers_Define__________//
 
# define    vi          vector<int>
# define    vll         vector<long long>
# define    vull        vector<unsigned long long>
# define    vvi         vector<vector<int> >
# define    vvll        vector<vector<long long> >
# define    vvull       vector<vector<unsigned long long> >
# define    vs          vector<string>
# define    vvs         vector<vector<string> >
# define    vpi         vector<pair<int, int> >
# define    vvpi        vector<vector<pair<int, int> > >
# define    pii         pair<int, int>
# define    pis         pair<int, string>
# define    psi         pair<string, int>
# define    mpii        map<int, int>
# define    mpis        map<int, string>
# define    mpsi        map<string, int>
# define    mpiv        map<int, vector<int> >
# define    umpii       unordered_map<int, int>
# define    umpis       unordered_map<int, string>
# define    umpsi       unordered_map<string, int>
# define    umpiv       unordered_map<int, vector<int> >
 
 
//_____________Data_type________________//
 
# define    ll          long long
# define    ull         unsigned long long
 
//_____________Methods__________________//
 
# define    mp          make_pair 
# define    pb          push_back 
# define    pf          push_front
# define    f           first    
# define    s           second   
 
# define    srt(v)      sort(v.begin(), v.end())
# define    ub(v, trg)  upper_bound(v.begin(), v.end(), trg)
# define    lb(v, trg)  lower_bound(v.begin(), v.end(), trg)
 
using namespace std;
 
//______________Functions________________//
 
bool    isInt(double d)
{
    return ((double)(int)d - d == (double)0.00);
}
 
// ull     fact(ull n)
// {
//     ull res = 1;
    
//     while (n--) res *= (n + 1);
//     return (res);
// }
 
ull     C(ull n, ull k)
{
    vull    dpp(n + 1);
    vvull   dp(k + 1, dpp);
 
    for (int i=1; i<=n; i++) dp[1][i] = i;
    for (int i=2; i<=k; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (i > j)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
    }
    return (dp[k][n]);
}
 
vpi merge_intervals(vpi   intervals)
{
    pair<int, int>  v;
    vpi             ans;
    
    if (!intervals.size()) return (ans);
    sort(intervals.begin(), intervals.end());
    v.f = intervals[0].f;
    v.s = intervals[0].s;
    for (int i=1; i<intervals.size(); i++)
    {
        if (intervals[i].f > v.s)
        {
            ans.push_back(v);
            v.f = intervals[i].f;
            v.s = intervals[i].s;
        }
        else
        {
            v.f = min(v.f, intervals[i].f);
            v.s = max(v.s, intervals[i].s);
        }
    }
    ans.push_back(v);
    return (ans);
}
# define MOD 1000000007LL
 
bool    is_prime(ll n)
{
    if (n == 1) return (false);
    if (n == 2) return (true);
    if (n % 2 == 0)
        return (false);
    for (int i=3; i<=(ll)sqrt(n); i += 2)
        if (n % i == 0) return (false);
    return (true);
}
 
 
ull gcd(ull a, ull b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

ull     lcm(ull a, ull b)
{
        return ((a * b) / gcd(a, b));
}

ll     get_pairs(int nm, vll& v)
{
    ll  ans = 0;
    for (ll dv=1; dv <= sqrt(nm); dv++)
    {
        if (nm / dv == dv) continue ;
        if (nm % dv == 0)
        {
            if (v[nm / dv] == -1 or v[dv] == -1) continue ;
            if (v[nm / dv] + v[dv] == nm) ans++;
        }
    }
    return (ans);
}


ll      sum_suite_ari(ll a0, ll an, ll n)
{
        return ((n * (a0 + an)) / 2);
}

ll      suite(ll t0, ll tn)
{
        ll      n = (tn - t0 + 1);

        return ((n * (2 * t0 + (n - 1))) / 2);
}

#include <fstream>

std::ofstream   out;
std::ifstream   in;

void    open_files(const char* input, const char* output)
{

        in.open(input);
        out.open(output);
}

long long   dp( long long num, int pw, int mod)
{
    if ( pw == 0 )  return ( 1 );
    if ( pw == 1 )  return ( num );
    
    long long   ans = dp( num, pw / 2, mod );
    
    if ( pw % 2 == 0 )
        return ( ( ans * ans ) % mod );
    return  ( ( ( ( ans * ans ) % mod ) * num ) % mod );
}

long long   get(long long n)
{
    return ((n * (n - 1)) / 2);

}

// long long   get_inverse_prime( long long num, int m )
// {
//     return ( dp(num, m - 2) );
// }

// long long   get_inverse_unprimes( long long num, int n )
// {
    
// }
vector<bool>    is_primes( 1001, true );
vector<ll>      primes;

void            get_primes()
{
    for ( int i=2; i<is_primes.size(); i++ )
    {
        if ( !is_primes[i] ) continue ;
        
        for ( int k=2; i * k < is_primes.size(); k++ ) is_primes[ i * k ] = false;
        primes.push_back( i );
    }
}

bool    exist( string& s, string& f, int start)
{
    for ( int i=0; i<f.length() and start + i < s.length(); i++ )
    {
        if ( s[start + i] != f[i] ) return ( false );
    }
    return ( true );
}

long long construct_row( vector<long long>&  row, vector<long long>& dp, int d )
{
    dp[0] = row[0] + 1;

    multiset<long long>    s;

    s.insert( dp[0] );

    for ( int i=1; i<row.size(); i++ )
    {
        dp[i] = row[i] + 1 + (*s.begin());

        if ( i - d - 1 >= 0 )
            s.erase( s.find( dp[i - d - 1] ) );
        s.insert( dp[i] );
    }
    // for ( int i=0; i<row.size(); i++ )
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    // cout << dp.back() << " ";
    return ( dp.back() );
} 

// i - (i - k) - 1 <= d

// k - 1 <= d
// k <= d + 1

long long mod(ll num )
{
    return ( ( num % MOD) + MOD ) % MOD;
}

vector<bool>   ans(100001, false );

int is_binary( int n )
{
    // cout << "checl" << endl;
    // cout << n << endl;
    while (n)
    {
        if ( ((n % 10) != 0) and ((n % 10) != 1) )
        {
            // cout << "false " << n % 10 << endl;
            return (false);
        }
        n /= 10;
    }
    return (true);
}

void    construct()
{
    // cout << "here" << endl;
    for ( int i=1; i<ans.size(); i++ )
    {
        // cout << "here" << endl;
        if ( is_binary(i) )
        {
            // cout << is_binary(i) << endl;
            // cout << i << endl;
            ans[i] = true;
            continue ;
        }

        for ( int div=2; div * div <= i; div++ )
        {
            if ( i % div != 0 ) continue ;
            if ( ans[i / div] and ans[div] )
            {
                ans[i] = true;
                break ;
            }
        }
    }  
}

void    solve()
{
    long long n;

    cin >> n;
    if ( ans[n] )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int cases = 1;

    get_primes();
    construct();
    cin >> cases;
    // cout << primes.size() << endl;
    while (cases--)
        solve();
    return (0);
}
// 100
// 100
//   1
//  11