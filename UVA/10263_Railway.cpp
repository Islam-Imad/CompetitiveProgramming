
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define X first
#define Y second
#define EPS 1e-9
#define PI acos(-1)
#define vec(a, b) (b - a)
#define dotp(a, b) (conj(a) * b).real()
#define crossp(a, b) (conj(a) * b).imag()
#define same(a,b) (abs(a-b) < EPS)
#define normalize(a) (a/abs(a))

typedef complex<ld> P;

int dcmp(ld x, ld y)
{
    if (fabs(x - y) < 1e-9)
        return 0;
    return x < y ? -1 : 1;
}

ld from_deg_to_rad(ld deg)
{
    ld ret = deg * PI / 180.0;
    if (ret < 0)
        ret += 2 * PI;
    return ret;
}
ld from_rad_to_deg(ld rad)
{
    ld ret = rad * 180.0 / PI;
    if (ret < 0)
        ret += 360;
    return ret;
}

bool isCollinear(P a, P b, P c)
{
    return dcmp(crossp(vec(a, b), vec(a, c)), 0) == 0;
}
bool isPointOnRay(P a, P b, P c)
{
    if (!isCollinear(a, b, c))
        return false;
    return same(normalize(b - a), normalize(c - a));
}
bool isPointOnSegment(P a, P b, P c)
{
    ld d1 = abs(b - a), d2 = abs(c - a);
    return same(d1+d2,abs(a-b));
    return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}

void solve()
{
    pair<ld, ld> input;
    P p = {1, 1};
    while (cin >> input.X)
    {
        cin >> input.Y;
        p = {input.X, input.Y};
        int n;
        cin >> n;
        vector<P> v(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            cin >> input.X >> input.Y;
            v[i] = {input.X, input.Y};
            // cout << v[i] << '\n';
        }
        ld min_dist = 1e18, ans_x = 0, ans_y = 0;
        for (int i = 1; i <= n; ++i)
        {
            P ab = vec(v[i - 1], v[i]);
            ld t = dotp(ab, vec(v[i - 1], p)) / norm(ab);
            P r = v[i - 1] + t * ab;
            if (dcmp(t, 0) >= 0 && dcmp(t, 1) <= 0)
            {
                min_dist = min(min_dist, abs(p - r));
                if (min_dist == abs(p - r))
                {
                    ans_x = r.real();
                    ans_y = r.imag();
                }
            }
            min_dist = min(min_dist, abs(p - v[i - 1]));
            if (min_dist == abs(p - v[i - 1]))
            {
                ans_x = v[i - 1].real();
                ans_y = v[i - 1].imag();
            }
            min_dist = min(min_dist, abs(p - v[i]));
            if (min_dist == abs(p - v[i]))
            {
                ans_x = v[i].real();
                ans_y = v[i].imag();
            }
        }
        cout << fixed << setprecision(4) << ans_x << "\n" << ans_y << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin>>tc;
    while (tc--)
    {
        solve();
    }
}