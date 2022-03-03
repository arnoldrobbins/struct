# struct --- Convert Fortran into Ratfor

This is Brenda Baker's `struct` program.  It converts plain old Fortran
into Rational Fortran (ratfor).  The code here is taken from the TUHS
archives, starting with the V7 version, and progressing through V8 and
V10.  Overall, the code changed very little from the initial V7 version.
The branches `v7-code`, `v8-code` and `v10-code` have the respective
versions.

This program has always fascinated me. I have always thought that it was
extremely cool.  Besides preserving the code in one place, I wanted to
try to bring the code into the modern era, in terms of C language usage
and code formatting.  With the help of Jay Logue, I have succeeded.

## Program Structure

There are three components:

* `structure`, which reads Fortran and produces something that is almost Ratfor.

* `beautify`, which reads the output of `structure` and finishes the conversion.

* `struct.sh`, a shell script to run the other two components.

The original code was written in 1974, when C was much less developed than
it is now. In particular, it freely mixed `int` with `int *`, `int **` and
`char *`.

Needless to say, this kind of coding doesn't work very well on a modern
64-bit Linux system.  _However_, when compiled with `gcc -m32` for the
original 32-bit Intel architecture, even with the accompanying warnings, the
code worked!

## Changes Accomplished

* Use of ANSI-style function definitions and declarations.

* Code formatting converted to standard ``K&R'' style using tabs.

* Modern C usages: macros, standard header files, `bool`, `printf` format specifiers and so on.

* Use of standard string routines instead of home-grown versions.

* Scanner for `beautify` adapted for use with flex.

* Grammar and scanner for `beautify` adapted for modern Yacc with `%union`.

* Argument parsing for `structure` converted to use getopt.

* Code converted to use the modern `intptr_t` type instead of `int` where
necessary, with casts added.  This was done by Jay Logue, and enables
compiling and running on 64-bit systems.  I thank him.

## Papers

Dr. Baker's paper on `struct` may be found at
https://dl.acm.org/doi/abs/10.1145/321992.321999.

The `techmemo` directory contains scans of Dr. Baker's internal
Bell Labs memorandum on `struct`, as retrieved from
https://www.tuhs.org/Archive/Documentation/TechReports/Baker_Struct/bsbstruct.pdf.
This was kindly made available to TUHS by Doug McIlroy.

## The test Directory

The file `t.f` is the sample program in Dr. Baker's paper. `t.r` is
the result of running `struct` on it.

The file `rat.in.for` is the _Software Tools_ `ratfor` in Fortran
for bootstrapping. `structure.out` is the result of running `structure`
on it and `beautify.out` is the result of running `beautify` on
`structure.out`.

Still to go is a `Makefile` to run the comparisons.

#### Last Modified

Thu Mar  3 12:20:02 IST 2022
