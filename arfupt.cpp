#include <iostream> // c++ primer p246

// various notations,same signatures
const double *f1(const double ar[], int n);
const double *f2(const double[], int n);
const double *f3(const double *, int n);

int main()
{
    using namespace std;
    double av[3] = {1, 2, 3};

    // pointer to a function
    const double *(*p1)(const double *, int) = f1; // definiton and initialize
    auto p2 = f2;                                  // c++ 11 automatic type deduction
    // pre-c++ 11 can use the following code instead;
    // const double *(*p2) (const double*,int) f2;

    cout << "Using pointers to functions:\n";
    cout << "Address Value \n";
    cout << (*p1)(av, 3) << " : " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << " : " << *p2(av, 3) << endl; // c++ provide two ways to use function pointer to call function

    // pa an array of pointers
    // auto doesn't work with list initialization
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    // but it does work for initializing to a single value
    // pb a pointer to first element of pa
    auto pb = pa;
    // pre-c++ 11 can use the following code instead
    // const double * (**pb)(const double *,int) = pa
    cout << " \n Using an array of pointers to functions:\n";
    cout << " Address Value \n";
    for (int i = 0; i < 3; i++)
    {
        cout << pa[i](av, 3) << " : " << *pa[i](av, 3) << endl; // [] 's priority is higher than *;
    }

    cout << "\n Using a pointer to a pointer to a function :\n";
    cout << " Address Value\n";
    for (int i = 0; i < 3; i++)
    {
        cout << pb[i](av, 3) << " : " << *pb[i](av, 3) << endl;
    }

    // what about a pointer to an array of function pointers
    cout << "\n Using pointers to an array of function pointers:\n";
    cout << "Address Value \n";
    // easy way to declare pc
    auto pc = &pa; // usually with 2-D array
    // pre-c++ 11 can use the following code instead
    // const double *(*(*pc)[3])(const double *,int) = &pa;
    cout << (*pc)[0](av, 3) << " : " << *(*pc)[0](av, 3) << endl;
    // hard way to declare pd
    const double *(*(*pd)[3])(const double *, int) = &pa;
    // store return value in pdb
    const double *pdb = (*pd)[1](av, 3);
    cout << pdb << " : " << *pdb << endl;
    // alternative notation
    cout << (*(*pd)[2])(av, 3) << " : " << *(*(*pd)[2])(av, 3) << endl;

    // basicly,you can use typedef keyword to simplify these statement
    typedef double real;                                 // makes real another name for double
    typedef const double *(*p_fun)(const double *, int); // p_fun now a type name,you can use p_fun to define variable
    p_fun paother = f1;
    // use p_fun to simplify code definition
    p_fun paotherArray[3] = {f1, f2, f3};
    p_fun(*pdother)[3] = &pa;

    // how about three-D array ? when use pointer to different dimension ,we should pay attention to details;
    int threeDArray[2][3][4] = {{{0, 1, 2, 3}}, {{4, 5, 6, 7}}};
    int twoDArray [3][4] = {{7,8,9}};
    int oneArray [4] = {1,2,3,4}; 
    int (*p1D) [4] = &oneArray; // compiler pass,
    // int (*ap1D) [4] = & oneArray[0] // compiler can't pass,because cannot convert "int *" to "int (*) [4]"
    int (*p2D) [4] = &twoDArray[0]; // compiler pass
    int (*p3D) [3][4] = &threeDArray[0]; // the compile doesn't appear error shows that we get correct code
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << threeDArray[i][j][k] << " ";
            }
        }
    }
    cout << endl;
    // use p3D to have the same effect
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << (*(p3D + i))[j][k] << " ";
            }
        }
    }
    cout << endl;

    return 0;
}

// some rather dull functions
const double *f1(const double *ar, int n)
{
    return ar;
}

const double *f2(const double *ar, int n)
{
    return ar + 1;
}
const double *f3(const double *ar, int n)
{
    return ar + 2;
}