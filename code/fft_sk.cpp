int log = 20;
int N = 1 << log;

typedef complex<double> cd;

int rev[N];
cd root[N];

void init() {
    for (int i = 0; i != N; ++i)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (maxlog - 1));

    const double pi = acos(-1);
    for (int k = 1; k < maxn; k *= 2) {
        cd tmp(pi / k);
        root[k] = {1, 0};
        for (int i = 1; i < k; i++)
            root[k + i] = (i & 1) ? root[(k + i) >> 1] * tmp : root[(k + i) >> 1];
    }
}

void fft(vector<cd>& a) {
    for (int i = 0; i != N; ++i)
        if (rev[i] < i)
            swap(res[rev[i]], res[i]);
    for (int k = 1; k < maxn; k *= 2)
        for (int i = 0; i < maxn; i += 2 * k)
            for (int j = 0; j != k; ++j) {
                cd tmp = root[k + j] * res[i + j + k];
                res[i + j + k] = res[i + j] - tmp;
                res[i + j]     = res[i + j] + tmp;
            }
}

void inv_fft(vector<cd>& a) {
    fft(a);
    reverse(a.begin() + 1, a.end());
    
    for (cd& elem: a)
        elem /= N;
}
