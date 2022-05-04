#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

using test_cpp_t = long long (*)(
    long long p0,
    long long p1,
    long long p2,
    long long p3,
    long long p4,
    long long p5,
    long long p6,
    long long p7);

using test_asm_t = long long (*)(
    long long p0,
    long long p1,
    long long p2,
    long long p3,
    long long p4,
    long long p5,
    long long p6,
    long long p7);

using test_c_t =  long long (*)(
    long long p0,
    long long p1,
    long long p2,
    long long p3,
    long long p4,
    long long p5,
    long long p6,
    long long p7);

using test_f90_t_ = void (*)(
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

    void* mod = dlopen("lib001-call-conv-so.so", RTLD_LAZY);
    if(nullptr == mod)
    {
        const char* dlerr = dlerror();
        cout << dlerr << endl;
    }

    auto test_f90_ = (test_f90_t_)dlsym(mod, "test_f90_");
    test_f90_(&p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &sum3);

    auto test_c = (test_c_t)dlsym(mod, "test_c");
    long long sum2 = test_c(0, 1, 2, 3, 4, 5, 6, 7);
    cout << sum2 << endl;

    auto test_asm = (test_asm_t)dlsym(mod, "test_asm");
    long long sum1 = test_asm(0, 1, 2, 3, 4, 5, 6, 7);
    cout << sum1 << endl;

    auto test_cpp = (test_cpp_t)dlsym(mod, "test_cpp");
    long long sum = test_cpp(0, 1, 2, 3, 4, 5, 6, 7);
    cout << sum << endl;

    if(nullptr != mod)
    {
        dlclose(mod);
        mod = nullptr;
    }

    return sum;
}

int test_so(int argc, char **argv)
{
    return main_start(argc, argv);
}