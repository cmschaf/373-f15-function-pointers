/*
reverse_sort.c

overrides a weak reference to int compare(int, int)
defined in sort.h.  

reverses the order of the subtraction so
as to reverse the sort via the given function to 
the sort functions


Chad Schaffer
cmschaf@umich.edu

Made for EECS 373
10/2/2015

 */


int compare(int a, int b)
{
  return b - a;
}
