#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<int> subset_sum(std::vector<int> &v);

void subset_sum(std::vector<int> &v, int k, std::vector<int> &sums, int curr);

int main()
{

 std::vector<int> v = {5, 1, 2};
 subset_sum(v);

 return 0;
}

void subset_sum(std::vector<int> &v, int k, std::vector<int> &sums, int curr)
{

 if (k == v.size())
 {
  sums.push_back(curr);
  std::cout << curr << ' ';
  return;
 }

 subset_sum(v, k + 1, sums, curr);
 curr += v[k];
 subset_sum(v, k + 1, sums, curr);
 curr -= v[k];
}

std::vector<int> subset_sum(std::vector<int> &v)
{
 sort(v.begin(), v.end(), std::greater<int>());
 std::vector<int> sums;
 subset_sum(v, 0, sums, 0);
 return sums;
}
