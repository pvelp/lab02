#include <header.hpp>


int main() {
  const int L1 = 128;
  const int L2 = 12288;
  int *values = new int(9);
  int k = 16;
  filling_arr(values, count(L1, L2), k);
  values[8] = pow(2, 20)*3;

  print(values, count(L1, L2), std::cout);
  delete(values);
  // apple silicon 2 уровня кэша, первый = 128кб, второй = 8мб
  // 64kb < 128kb < 256kb << 512kb << 1Mb << 2mb << 4mb << 8mb << 12mb
}
