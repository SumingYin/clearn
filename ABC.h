#include <iostream>
class A
{
public:
    void f1();
    A(){i1 = 10;j1=i1}
protected:
    int j1;
private:
    int i1;
}

class B:private A
{
public:
    void f2();
    B(){i2 = 20;j2=i2}
protected:
    int j2;
private:
    int i2;
}
class C:private B
{
public:
    void f3();
    C(){i3 = 30;j3=i3}
protected:
    int j3;
private:
    int i3;
}
