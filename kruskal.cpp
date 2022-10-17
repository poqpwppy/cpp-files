#define NAME "kruskal"
#define ll long long
#define lli long long int

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100001;

int n,m,par[MaxN];

struct canh{
    int fst,scd,ts;
} a[MaxN];

void file(void) {
    if(fopen(NAME".inp","r")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
}

bool check(canh p, canh q) {
    return p.ts < q.ts;
}

int root(int x) {
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
}

void join(int p, int q) { par[root(p)] = root(q); }

void kruskal(void) {
    int u,v,t;

    cin >> n >> m;

    for(int i=1;i<=m;i++) {
        cin >> u >> v >> t;
        a[i].fst = u;
        a[i].scd = v;
        a[i].ts = t;
    }

    for(int i=1;i<=n;i++) {
        par[i] = i;
    }

    sort(a+1,a+m+1,check);

    for(int i=1;i<=m;i++) {
        if(root(a[i].fst) != root(a[i].scd)) {
            join(a[i].fst, a[i].scd);
            cout << a[i].fst << " " << a[i].scd << "\n";
        }
    }

    /*for(int i=1;i<=m;i++) {
        cout << a[i].fst << " " << a[i].scd << " " << a[i].ts << "\n";
    }*/
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    file();

    kruskal();

    return 0;
}
