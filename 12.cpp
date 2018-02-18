 /*    
 *  newb    
 *  IIIT Allahabad
 */

#include <bits/stdc++.h>
#include "pretty_print.h"
using namespace std;

/***TEMPLATE***/
#define intt long long

#define pii pair<intt,intt>
#define vi vector<intt>
#define vii vector<pii>
#define vvi vector<vi>

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define CONTAINS(a, x) (a.find(x) != a.end())
#define SZ(x) (int)x.size()
#define CASET int ___T, case_n = 1; scanf("%d", &___T); while (___T-- > 0) 


#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mt make_tuple

#define endl '\n'
#define nl cout << endl

#define wtfis(x) cerr << "at line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define what_is(x) cout << #x << " = " << x << endl
#define boost ios::sync_with_stdio(false);cin.tie(NULL)

const intt max3 = 1003;
const intt max4 = 10004;
const intt max5 = 100005;
const intt max6 = 1000006;
const intt max7 = 10000007;

const intt lg4 = 13;
const intt lg5 = 17;
const intt lg6 = 20;

const intt INF = 2LL * 1000000000;
const intt INFLL = 9LL * 1000000000 * 1000000000;
const intt M = 1e9 + 7;
/***************/

intt powmod (intt a, intt b, intt mod) {
    intt res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

intt gcd (intt a, intt b) {
    while (b > 0) {
        intt t = a % b;
        a = b, b = t;
    }
    return a;
}

intt lcm (intt a, intt b) {
    return (a / gcd (a, b)) * b;
}

intt is_prime (intt n) {
    if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0))
        return 0;
    for (intt i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
        if (n % i == 0)
            return 0;
    return 1;
}
/**************************/
intt val[max7];
int primes[max7];
int main() {
    boost;
    if(fopen("input.txt", "r")){
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    }
    memset(primes, 0, sizeof(primes));
    vi pf;
    primes[0] = primes[1] = 1;
    for(int i = 2;(i * i) < max7;i++){
        if(primes[i] == 0){
            for(int j = i * i;j < max7;j += i)
                primes[j] = 1;
        }
    }
    for(int i = 0;i < max7;i++)
    	if(primes[i] == 0)
    		pf.pb(i);

    map<intt, intt> prev, curr, temp;
	for(intt i = 2;i < max7;i++){
		intt n = i;
		int idx = 0;
		intt PF = pf[idx];
	    while(PF * PF < n){
	        while(n % PF == 0){
	            n /= PF;
	            curr[PF]++;
	        }
	        idx++; 
	    	PF = pf[idx];
	    }
	    if(n > 1)
	    	curr[n]++;

	    intt t = 1;
	    temp.clear();
	    /*
		    tn = (n * (n + 1)) / 2
		    n and n + 1 have no common prime factors...just add prev and curr
		    prime factors than subtract 1 from temp[2] a (/2).
	    */
	    for(auto it : prev){
	    	temp[it.F] += it.S;
	    }
	    for(auto it : curr){
	    	temp[it.F] += it.S;
	    }
	    temp[2]--;
	    for(auto it : temp){
	    	t *= (it.S + 1);
	    }
	    prev = curr;
	    curr.clear();
	    if(t > 500){
	    	cout << (i * (i - 1)) / 2 << "\n";
	    	break;
	    }
	}
    return 0;
}

//  Train Insane or Remain the same
