#include <iostream>
#include "L0903_329.hpp"
int main()
{
  std::cout<<is_a_solution(nullptr,1,2)<<std::endl; //0
  std::cout<<is_a_solution(nullptr,2,2)<<std::endl; //1
  std::cout<<is_a_solution(nullptr,2,1)<<std::endl; //0
  int testarray[10];
  int count;
  construct_candidates(nullptr,0,0,testarray,&count);
  for (int i = 0; i < count; ++i) //1 0 2
    std::cout<<testarray[i]<<" ";
  std::cout<<count;
  int a[10] = {true, true, true, true, false, true, false, false, true, false};
  process_solution(a, 8, 0); //{ 1 2 3 5 8 }
}