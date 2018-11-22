//p[i] -- prefix (id of first symbol) on i-th position of suff array (from 0) 
for (int i = 0; i < n; i++)
    r[p[i]] = i;
int k = 0;
for (int j = 0; j < n; j++){
    int i = r[j];
    k--;
    if (k < 0 || i == n - 1)
        k = 0;
    if (i != n - 1)
        while (s[p[i] + k] == s[p[i + 1] + k])
            k++;
    lcp[i] = k;
}
for (int i = 0; i + 1 < n; i++)
    cout << lcp[i] << " ";
