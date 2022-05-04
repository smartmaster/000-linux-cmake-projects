#include <iostream>

extern long long test_cpp(
    long long p0,
    long long p1,
    long long p2,
    long long p3,
    long long p4,
    long long p5,
    long long p6,
    long long p7);

extern "C" long long test_asm(
    long long p0,
    long long p1,
    long long p2,
    long long p3,
    long long p4,
    long long p5,
    long long p6,
    long long p7);

extern "C" long long test_c(
    long long p0,
    long long p1,
    long long p2,
    long long p3,
    long long p4,
    long long p5,
    long long p6,
    long long p7);

extern "C" void test_f90_(
    long long *p0,
    long long *p1,
    long long *p2,
    long long *p3,
    long long *p4,
    long long *p5,
    long long *p6,
    long long *p7,
    long long *sum);

static int main_start(int argc, char **argv)
{
    using namespace ::std;

    long long p0 = 0;
    long long p1 = 1;
    long long p2 = 2;
    long long p3 = 3;
    long long p4 = 4;
    long long p5 = 5;
    long long p6 = 6;
    long long p7 = 7;
    long long sum3 = 0;
    test_f90_(&p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &sum3);

    long long sum2 = test_c(0, 1, 2, 3, 4, 5, 6, 7);
    cout << sum2 << endl;

    long long sum1 = test_asm(0, 1, 2, 3, 4, 5, 6, 7);
    cout << sum1 << endl;

    long long sum = test_cpp(0, 1, 2, 3, 4, 5, 6, 7);
    cout << sum << endl;

    return sum;
}

static int main_000(int argc, char **argv)
{
    return main_start(argc, argv);
}