#include "L0905_330.hpp"
#include <iostream>
const int NMAX = 100;
int main()
{
  int a[4] = {3,6,7};
  int k = 3;
  int n = 10;
  int c[NMAX];
  int nc;

  construct_candidates(a,k,n,c,&nc);
  for (int i=0; i<nc; ++i)
  {
    std::cout<<i<<": "<<c[i]<<std::endl;
  }
  std::cout<<std::endl;
}
