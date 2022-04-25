#include <iostream>
#include <vector>
#include <string>
using namespace std;

void show_array(const double *ar[], int n); // ar array store double pointer
void show_array(const double ar[], int n);  // basic type value point ar

int main()
{
    double a = 1.0;
    double b = 2.0;
    double c = 3.0;
    double *dptAr[3]{&a, &b, &c};
    // show_array(dptAr, 3); //two relationship, invalid ,detail see the book c primer page 222-224
    double dAr [3] {a,b,c};
    show_array(dAr,3); // valid only one direct relationship 

    // arr[i] == *(arr + i) values in two notations
    // &arr[i] == arr + i  addresses in two notations
    int age = 39;
    int *pd = &age;

    const int *pt = pd; // not const pointer assign to const pointer

    const int **pp2; // pointer pointer
    int *p1;
    int *p2;
    const int n = 13;
    int n2 = 0;
    p2 = &n2;
    // pp2 = &p1; // compile error invalid conversion from "int **" to "const int **"

    *pp2 = p2;
    // *pp2 p1 p2 should be the memory address of n2
    cout << **pp2 << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;

    *pp2 = &n; // valid,both const
    *p1 = 10;  // valid ,but changes const n,here suppose pp2 = &p1 successfully
    cout << "value of n: " << n << endl;

    vector<string> msg{"Hello", "c++", "from", "VS code", "and the c++ extension!"};
    for (const string &word : msg)
    {
        cout << word << " ";
    }
    int i;
    cin >> i;
    if (cin)
    {
        cout << "true"
             << "value of i:"
             << i
             << endl;
    }
    else
    {
        cout << "false"
             << "value of i:"
             << i
             << endl;
    }

    return 0;
}
// invalid conversion from "double **" to "const doule**" 
// void show_array(const double *ar[], int n)
// {

//     for (int i = 0; i < n; i++)
//     {
//         cout << **(ar + i) << endl;
//     }
// }
// valid conversion
void show_array(const double ar[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << *(ar + i) << endl;
    }
}