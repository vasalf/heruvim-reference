
struct treap{
    map<char, int> go;
    int len, suff;
    long long sum_in;
    treap(){}
};

treap v[max_n * 4];
int last = 0;

int add_treap(int max_len){
    v[number].sum_in = 0;
    v[number].len = max_len;
    v[number].suff = -1;
    number++;
    return number - 1;
}

void add_char(char c){
    int cur = last;
    int new_treap = add_treap(v[cur].len + 1);
    last = new_treap;
    while (cur != -1){
        if (v[cur].go.count(c) == 0){
            v[cur].go[c] = new_treap;
            v[new_treap].sum_in += v[cur].sum_in;
            cur = v[cur].suff;
            if (cur == -1)
                v[new_treap].suff = 0;
        }else{
            int a = v[cur].go[c];
            if (v[a].len == v[cur].len + 1){
                v[new_treap].suff = a;
            }else{
                int b = add_treap(v[cur].len + 1);
                v[b].go = v[a].go;
                v[b].suff = v[a].suff;
                v[new_treap].suff = b;
                while (cur != -1 && v[cur].go.count(c) != 0 && v[cur].go[c] == a){
                    v[cur].go[c] = b;
                    v[a].sum_in -= v[cur].sum_in;
                    v[b].sum_in += v[cur].sum_in;
                    cur = v[cur].suff;
                }
                v[a].suff = b;
            }
            return;
        }
    }
}

