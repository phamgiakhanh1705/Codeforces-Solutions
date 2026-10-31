#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
 
struct Node
{
    int len;             
    int nxt[4];           
    int delta[4];         
    Node(int _len = 0)
    {
        len = _len;
        for(int d = 1; d <= 3; ++d)
        {
            nxt[d] = d;
            delta[d] = 0;
        }
    }
};
 
int n , q;
vector<int> p;             
vector<int> pow2;          
vector<Node> seg;
int SZ;
 
Node make_leaf(int peg)           
{
    Node v(1);
    for(int dest = 1; dest <= 3; ++dest)
    {
        if(peg == dest)
        {
            v.delta[dest] = 0;
            v.nxt[dest]   = dest;
        }
        else
        {
            v.delta[dest] = 1;                 
            v.nxt[dest]   = 6 - peg - dest;    
        }
    }
    return v;
}
 
Node merge(const Node &L , const Node &R)      
{
    if(!L.len) return R;
    if(!R.len) return L;
 
    Node res;
    res.len = L.len + R.len;
    int shift = pow2[L.len];                  
 
    for(int dest = 1; dest <= 3; ++dest)
    {
        int mid   = R.nxt[dest];              
        long long add = (1LL * R.delta[dest] * shift + L.delta[mid]) % MOD;
 
        res.delta[dest] = int(add);
        res.nxt[dest]   = L.nxt[mid];
    }
    return res;
}
 
void build()
{
    SZ = 1; while(SZ < n) SZ <<= 1;
    seg.assign(2*SZ , Node());
 
    for(int i = 1; i <= n; ++i)
        seg[SZ+i-1] = make_leaf(p[i]);
 
    for(int i = SZ-1; i >= 1; --i)
        seg[i] = merge(seg[i<<1] , seg[i<<1|1]);
}
 
void point_update(int idx , int val)          
{
    int pos = SZ + idx - 1;
    seg[pos] = make_leaf(val);
    for(pos >>= 1; pos; pos >>= 1)
        seg[pos] = merge(seg[pos<<1] , seg[pos<<1|1]);
}
 
Node range_query(int l , int r)                
{
    Node left , right;                         
    for(l += SZ-1 , r += SZ-1 ; l <= r ; l >>= 1 , r >>= 1)
    {
        if(l & 1)      left  = merge(left , seg[l++]);   
        if(!(r & 1))   right = merge(seg[r--] , right);  
    }
    return merge(left , right);                
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> q;
    p.resize(n+1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
 
    pow2.resize(n+2);
    pow2[0] = 1;
    for(int i = 1; i <= n+1; ++i)
        pow2[i] = int( (pow2[i-1]*2LL) % MOD );
 
    build();
 
    while(q--)
    {
        char type; cin >> type;
        if(type == 'c')                       // change
        {
            int x , y; cin >> x >> y;
            point_update(x , y);
        }
        else                                  // solve
        {
            int l , r; cin >> l >> r;
            Node res = range_query(l , r);
            cout << res.delta[1] % MOD << '\n';   
        }
    }
    return 0;
}