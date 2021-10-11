#include <header.hpp>

int main() {
  Cache *tests = (Cache*)(malloc(sizeof(Cache)*9));
  int *values = (int*)(malloc(sizeof (int)*9));
  int k = 16;
  for (int i = 0; i < 8; ++i){
    values[i] = pow(2, k)/4;
    k++;
  }
  values[8] = pow(2, 20)*3;

  for (int i = 0; i < 9; ++i){
    tests[i] = Cache(values[i]);
    tests[i].experiment();
    std::cout << "Test[" << i << "] - direction: " << tests[i].get_res_dir_test() << " | reverse: " << tests[i].get_res_rev_test()
      << " | random: " << tests[i].get_res_rand_test() << std::endl;
    tests[i].delete_arr();
  }
  delete(tests);
  delete(values);

  // apple silicon 2 уровня кэша, первый = 128кб, второй = 8мб
  // 64kb < 128kb < 256kb << 512kb << 1Mb << 2mb << 4mb << 8mb << 12mb
}
