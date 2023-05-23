struct NODE
{
    NODE(int a, int l, int r)
    {
        this->a = a;
        this->l = l;
        this->r = r;
    }
    NODE () {}
    int a, l, r;

} tree[4*mxn];

//Declaration 
NODE temp = {0, 0, 0};