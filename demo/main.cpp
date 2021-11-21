int fun(int a, int b){
    int r = 0;
    while (!((a & 1) || (b & 1))){
        a >>= 1;
        b >>= 1;
        r++;
    }
    while (true){
        while (!(a & 1)) a >>= 1;
        while (!(b & 1)) b >>= 1;
        if (a>b) a = a-b;
        else b = b-a;
        if (a == 0) return b << r;
        if (b == 0) return a << r;
    }
}