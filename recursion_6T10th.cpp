#include <iostream>
using namespace std;

/*
    Epi6. Recursion -  1. When a function calls itself
                 2. Until a specify condition is met, // that condition is called base condition

    definition of point 1.  f()
                            {
                                ...
                                ..
                                f()
                            }

                        exa- void f()                       void f()                        void f()
                             {                              {                               {
                                cout << "1";                    cout << "1";                    cout << "1";
                                f(); //this get next void       f(); //this get next void       f();
                             }                              }                               }
                             int main()
                             {
                                f();
                             }

                             above void is keep getting repeated bcz there is no break condition, then it will falls under infinite recursion
                             from above we get the OutPut-  1, 1, 1  // from above 3 voids

    explanation for condition 2.    cnt = 0
                                    f()                 f()                 f()                 f()
                                    {                   {                   {                   {
                                        if(cnt == 3)        if(cnt == 3)        if(cnt == 3)        if(cnt == 3)
                                            return;             return;             return;             return;
                                        cout << cnt;        cout << cnt;        cout << cnt;        cout << cnt;    // these three lines will not get executed bcz
                                        cnt++;              cnt++;              cnt++;              cnt++;          // we got the base condition of "cnt == 3"
                                        f();                f();                f();                f();
                                    }                   }                   }                   }
                                    int main()
                                    {
                                    f();
                                    }

                                    we got the OutPut- 0(in first), 1(in second), 2(in third), 4(in forth)

    Actual Code of Recursion
#include<iostream>
using namespace std;

int cnt = 0;
void print()
{
    if(cnt == 3)
        return;
    cout << cnt << endl;
    cnt++;
    print();
}
int main()
{
    print();

    return 0;
}
    OutPut- 0, 1, 2


    from condition 2. explanation we get as         ->    ->    ->
                                                f()    f()   f()   f()      in the last function we got our output
                                                    <-    <-    <-          // This tree of function calling fwd and getting bckwrd(after getting output)
                                                                            // is called RECURSION TREE
*/



/*
         Epi7. Basic Recursion Problems -
                                    Print Name 5 times
                                    Print linearly from 1 to N
                                    Print from N to 1
                                    Print linearly from 1 to N (but by backtrack)
                                    Print from N to 1 (by backtrack)


1. Print Name 5(or N) times, using recursion

void f(i, n)
{
    if(i > n)
        return;         // this line and line above, both called 'Base Condition'
    cout << "vasu";
    f(i + n);
}
    
int main()
{
    int n;
    cin >> n;
    f(1, n);
}
        TC - O(N)
        SC(space complexity)/stack space - O(N)


2. Print Linearly from 1 to N
        exam- if N=4, o/p will be- 1, 2, 3, 4

void f(i, N)
{
    if(i > N)
        return;
    cout << i;
    f(i + 1, N);
}

int main()
{
    int N;
    cin >> i;
    f(1, N);
}


3. Print from N to 1
        exam- if N=4, o/p will be- 4, 3, 2, 1

void f(i, N)
{
    if(i < 1)
        return;
    cout << i;
    f(i - 1, N);
}

int main()
{
    int N;
    cin >> N;
    f(N, N);
}


4, Print linearly from 1 to N (but by backtrack)
        exam- we can't do f(i + 1, N)

void f(i, N)
{
    if(i < 1)
        return;
    f(i - 1, N);
    cout << i;
}

int main()
{
    int N;
    cin >> N;
    f(N, N);
}

        explanation-                                ->    ->    ->
                                                f()    f()   f()   f()      the o/p will get printed when the functions goes
                                                    <-    <-    <-          from last to first(i.e in backwards direction), which is 1, 2, 3, ...
                                                                            bcz we kept the 'print' after the function call
        recursion tree for this prblem-     f(3, 3)     print(3)
                                               |           ^
                                                           |
                                            f(2, 3)     print(2)
                                               |           ^
                                                           |
                                            f(1, 3)     print(1)
                                               |
                                                           ^
                                            f(0, 3) ->     |


        5.Print from N to 1 (by backtrack)

void f(i, N)
{
    if(i > N)
        return;
    f(i + 1, N);
    cout << i;
}

int main()
{
    int N;
    cin >> N;
    f(1, N);
}
*/


/*
            Epi8. Parameterised and Functional recursion
                        problems- 1. Sum of first N nmbrs(will be doing this by using 2 methods- parameterised and functional)


    1st Parameterised way

void f(i, sum)              f(3, 0)                 f(2, 3)                 f(1, 5)                 f(0, 6)
{                           {                       {                       {                       {
    if(i < 1)               whole if condition      whole if condition      whole if condition          if(i < 1)           // <-this condition is true
    {                       will not get            will not get            will not get                {
        cout << sum;        executed                executed                executed                        cout << sum;    // sum
        return;                                                                                              return;
    }                       }                       }                       }                           }
    f(i - 1, sum + i)       f(3 - 1, 0 + 3)         f(2 - 1, 3 + 2)         f(1 - 1, 5 + 1)             // <-this line will not get executed
}                                                                                                       // and we get o/p of '6'

int main()
{
    int n;
    cin >> n;
    f(n, 0);        // n is i, '0' is sum   lets take n = 3
}

        recursive tree -    f(i, sum) -> f(3, 0) -> f(2, 3) -> f(1, 5) -> f(0, 6)


    2nd Functional way
            (we don't to print value but to expect to return value in functional way)

    explanation- lets take n=3, then we can say this
                    3 + f(2)                    // we know f(n)-> sum of first N nmbrs
              where f(2) -> 2 + f(1)
                    f(1) -> 1 + f(0),       where f(0) = 0

f(n)                        f(3)                    f(2)    //from return   f(1)                    f(0)
{                           {                       {                       {                       {
    if(n == 0)              not                     not                     not                         if(n == 0)
        return 0;           executed                executed                executed                        return 0;
    
    return n + f(n - 1);    return 3 + f(3 - 1);    return 2 + f(2 - 1);    return 1 + f(1 - 1);    not executed
}                           }                       }                       }                       }
int main()
{
    int n;          //lets take n=3
    cin >> n;
    print(f(n));
}

        explanation --  in the 4th we got f(0)->0, this '0' returns to f(1) and we got 1 + f(0) -> 1 + 0 = 1
                        by this f(2)-> 2 + 1 = 3,  f(3)-> 3 + 3 = 6
                        and we get the o/p - 6


        Actual Code
#include<iostream>
using namespace std;

int sum(int n)
{
    if(n == 0)
        return 0;

    return n + f(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << sum(n);

    return 0;
}


            problem 2. find the Factorial

        Functional recursion            TC -> O(N)
                                        SC -> O(N)
    Actual Code
#include<iostream>
using namespace std;

int fact(int n)
{
    if(n == 0)
        return 1;

    return n * f(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << fact(n);

    return 0;
}


        Parameterised way (self solved)

    Code
#include<iostream>
using namespace std;

int fact(i, fac)
{
    if(i == 1)
    {
        cout << fac;
        return;
    }
    fact(i - 1, fac * i)
}
int main()
{
    int n;
    cin >> n;
    fact(n, 1);
}
*/


/*
                9. episode    OR Re 4

            problem- Reverse an array
                        {1, 2, 3, 4, 2} -> {2, 4, 3, 2, 1}


        Actual Code     (using different method)
// Iterative C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;

// Function to reverse arr[] from start to end
void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;            // or swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Utility function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

// Driver function to test above functions
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };

    int n = sizeof(arr) / sizeof(arr[0]);

    // To print original array 
    printArray(arr, n);

    // Function calling
    rvereseArray(arr, 0, n - 1);

    cout << "Reversed array is" << endl;

    // To print the Reversed array
    printArray(arr, n);

    return 0;
}

        Pseudo Code of above actual code (using recursion)      
                    // {1, 3, 2, 5, 4}
                    // 'l' is 0th index, 'r' is (n-1)th index
f(l, r)                 f(0, 4)             f(1, 3)             f(2, 2)
{                       {                   {                   {
    if(l >= r)          not                 not                 if(2 >= 2)
        return;         executed            executed                return;

    swap(a[l], a[r]);   swap(a[0], a[4]);   swap(a[1], a[3]);   not
    f(l + 1, r - 1);    f(0 + 1, 4 - 1);    f(1 + 1, 3 - 1);    executed
}                       }                   }                   }
int main()
{
    arr[];
    f(0, n-1);
}


        solving the above code using single variable(i.e Pointer)
                // arr -> {1, 2, 3, 4, 5}
                // then - 'l' is 'i' and 'r' is '(n - i - 1)'

f(i)                            f(0)                f(1)                f(2)                
{                               {                   {                   {                   
    if(i >= n/2)                not                 not                 if(2 >= 5/2)                 
        return;                 executed            executed            

    swap(a[i], a[n - i - 1]);   swap(a[0], a[4]);   swap(a[1], a[3]);   not
    f(i + 1);                   f(0 + 1);           f(1 + 1);           executed
}                               }                   }                   }
int main()
{
    a[];
    f(0);
}
    

            Actual Code
#include<iostream>
using namespace std;

void f(int i, arr[], int n)
{
    if(i >= n/2)
        return;

    swap(arr[i], arr[n - i - 1]);
    f(i + 1, arr, n);
}
int main()
{
    int n;
    cin >> n;

    // i/p of array
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    f(0, arr, n);

    // printing the array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


                problem- check if a string is palindrome or not

        pseudo code (functional way)
f(i)                            f(0)                f(1)                f(2)
{                               {                   {                   {
    if(i >= n/2)                n                   n                   if(2 >= 5/2)
        return true;            e                   e                       return true;        // <- if returned true, it will print 'palindrome' in main()

    if(s[i] != s[n - i - 1])    if(s[0] != s[4])    if(s[1] != s[3])    n                       // <- it is checking 'if the elements are equal or not'
        return false;               return false;       return false;   e                       // <- if returned false, it will print 'not a palindrome' in main()
    return f(i + 1);            return f(0 + 1);    return f(1 + 1);
}                               }                   }                   }
int main()
{
    print f(0);
}


        Actual Code
#include<iostream>
using namespace std;

bool f(int i, string &s)
{
    if(i >= s.size()/2)
        return true;

    if(s[i] != s[s.size() - i - 1])
        return false;
    return f(i + 1, s);
}
int main()
{
    string s = "madam";
    cout << f(0, s);

    return 0;
}

                TC - O(N/2)
                SC - O(N/2)
*/



/*
                    epi 10.  Re5. Multiple Recursion calls
                    
                    exam- f()
                          {
                          ..
                          ...
                          f()
                          f()       // this function is called two times(multiple) 
                          }

                        Problem- Fibonacci nmbr

            Fibonacci using For loop
        f[0] = 0,  f[1] = 1

        for(i = 2 -> n)
            f[i] = f[i - 1] + f[i - 2]


            using recursion
        f(n)                        f(4)    // watch video for explanation
        {                           {
            if(n <= 1)              n
                return n;           e

            last = f(n - 1);        
            slast = f(n - 2);
            return last + slast;
        }
        main()
        {
            n;              // <- take n=4
            print(f(n));
        }
        
        recursion tree for fibonacci
                    f(4)
                     /\
                    /  \
               f(3)      f(2)           // by solving the explanation(from the video) we get
                /\        /\            // f(0)=0, f(1)= 1,  by this we get
             f(2) f(1) f(1) f(0)        // f(2)= 1,  f(3)= 2,  f(4)= 3
              /\
           f(1) f(0)

        Actual Code
int f(int n)
{
    if(n <= 1)
        return n;

    int last = f(n - 1);
    int slast = f(n - 2);
    return last + slast;
}
int main()
{
    cout << f(4);
}

            TC - O(2^N)     <- but this O(2^N) is exponential in nature
*/


/*
                epi 11.  L6. Recursion on Subsequence
                                Print all Subsequence       // prefer to "love babbar" lecture for this video

                        Subsequence -  a contiguous or non-contiguous sequence,
                                        which follows the order
                                exa- arr[]-> {3, 1, 2}, where 3
                                                              1
                                                              2
                                                              31
                                                              12
                                                              32   <- all are contiguous exept this one 
                                                              312 these are all subsequence
                                                              321 is not subsequence, bcz it is not following the order
                                                                    // '3' has to be before 1 and/ 2(as in 32), '2' has to be after 3 and/ 1

                note- for any given set(array), we can find its nmbr of subsets by "POWER SET" method,
                        but here we are solving it by recursive method

        lets take same example {3,1, 2}, we can get its subsets by taking an not taking the indexes
        like  {take, not take, take} -> {3, 2},  we can get various patterns using this method


        lets take same array -> {3, 1, 2}
                    indexes  ->  0  1  2

        Pseudo code
f(ind, [])              // ind for index, [] is vector or any data structure
{
    if(n >= 2)
        print([])
        return;

    [].push_back(arr[i]);
    f(ind + 1, []);         // <- take
    [].remove(arr[i]);
    f(ind + 1, []);         // <- not take
}
main()
{
    arr -> {3, 1, 2}
    f(0, [])
}


        Actual Code
#include<iostream>
using namespace std;

void printF(int ind, vector<int> & ds, int arr[], int n)        // ds for data structure
{
    if(ind == n)
    {
        for(auto it : ds)
        {
            cout << it << " ";
        }
        if(ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    // not take or not pick condition, these element is not added to subsequence
    printF(ind + 1, ds, arr, n);

    // take or pickthe particular index into the subsequence
    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);
    ds.pop_back();
}
int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    printF(0, ds, arr, n);
}

                TC -> O(2^n × n)
                SC -> O(n)
*/



/*
                        epi.12      L7.  All kind of Patterns in Recursion

                                problem- Printing Subsequences whose Sum is K

            Pseudo Code 
f(i, _, s)
{
    if(i == n)
    {
        if(s == sum)
            print(ds)
        return;
    }
    ds.add(arr[]);
    s += arr[i]
    f(i + 1, ds, s)
    ds.remove(arr[i])
    s -= arr[i]                 // <- these 5 lines are take case

    f(i + 1, ds, s)             // <- not take case
}

        Actual Code
#include<iostream>
using namespace std;

void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if(int == n)
    {
        if(s == sum)
        {
            for(auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    printS(ind + 1, ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();

    // not take
    printS(ind + 1, ds, s, sum, arr, n);
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);

    return 0;
}


                        problem- print any '1' subsequences whose sum is sum
                                        // {1, 1} = 2, but {2} != 2

        pseudo code (to print one answer)
bool f()
{
    base case
        condition->satisfied
            return true;
        condition->not satisfied
            return false;

    if(f() == true)
        return;

    f()

    return false;
}

        Actual Code (above actual code)
#include<iostream>
using namespace std;

bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if(int == n)
    {
        // condition satisfied
        if(s == sum)
        {
            for(auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;                    // <- new line
        }
        // condition not satisfied
        else
            return false;                   // <- new lines
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printS(ind + 1, ds, s, sum, arr, n) == true)     // <- new
    {
        return true;                                    // <- new
    }

    s -= arr[ind];
    ds.pop_back();

    // not take
    if(printS(ind + 1, ds, s, sum, arr, n) == true)     // <- new 
        return true;                                    // <- new

    return false;                                       // <- new
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);

    return 0;
}



                        problem- Count the Subsequences with sum = K
                                exam- {1, 2, 1}, sum=2; here count = 2 subsequence

        pseudo code
int f()
{
    base case
        return 1 -> condition satisfies
        return 0 -> condition not satisfies

    l = f()         // l for left       <-- these two are for only 2 recursion      s = 0 
    r = f()         // r for right      <-| calls, but for multiple -- >            for(i = 1 -> n)
                                                                                        s += f();
    return l + r;                                                                   return s;
}


        Actual Code (from above actual code)
#include<iostream>
using namespace std;

int printS(int ind, int s, int sum, int arr[], int n)
{
    // condotion not satisfied
    //  strictly done if array contains positive only
    if(s > sum)
        return 0;

    if(int == n)
    {
        // condition satisfied
        if(s == sum)
        {
            return 1;                    // <- new line
        }
        // condition not satisfied
        else
            return 0;                   // <- new lines
    }

    s += arr[ind];

    int l = printS(ind + 1, s, sum, arr, n);     // <- new

    s -= arr[ind];

    // not take
    int r = printS(ind + 1, s, sum, arr, n)     // <- new

    return l + r;                                       // <- new
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    cout << printS(0, 0, sum, arr, n);

    return 0;
}

                    TC -> O(2^N)
*/
int main()
{
    cout << "Hello World!\n";
}