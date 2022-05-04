subroutine test_f90_in_exe(p0, p1, p2, p3, p4, p5, p6 , p7, result)
    implicit none
    integer*8 p0
    integer*8 p1
    integer*8 p2
    integer*8 p3
    integer*8 p4
    integer*8 p5
    integer*8 p6
    integer*8 p7
    integer*8 result

    result = 0
    result = result + p0
    result = result + p1
    result = result + p2
    result = result + p3
    result = result + p4
    result = result + p5
    result = result + p6
    result = result + p7

    write(*,*) "the sum is ", result

end subroutine
