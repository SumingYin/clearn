
long indeed(int);
long indeed(int n)
{
    return n;
}
template <typename Type>
void recycle(Type t);
template <typename Type>
void recycle(Type *t);
struct blot
{
    int a;
    char b[10]
};
blot ink = {25, "spots"};
recycle(&ink); // this will use void recycle(Type *t) because it's more specific

int main()
{
    decltype(indeed(3)) m; // m is long type,c++ primer at page 296 is wrong
    int x;
    double y;
    typedef decltype(x + y) xy; // use typedef and decltype to announce a new type xy,then we can use this multiple times;
    xy a,b;

    double xx = 2.2;
    decltype(xx) valx; // double valx
    decltype((xx)) refx; // double & refx
}

// when use function template,if we want to return a unknown type vlaue ,we can use "auto style" function announcement
// the reason why we can't use the formal declarsion is that the compiler don't know the real type of return value;
// here is example,this is also called trailing return type
template<typename T1,typename T2>
auto add<T1 x,T2 y> -> decltype(x + y)
{
    // function contents
    return x+y;
}
