#include <header.hpp>

int main() {
  Cache *tests = (Cache*)(malloc(sizeof(Cache)*9));
  int *values = (int*)(malloc)(sizeof (int)*9);
  int k = 16;
  for (int i = 0; i < 8; ++i){
    values[i] = pow(2, k)/4;
    k++;
  }
  values[8] = pow(2, 20)*3;

  for (int i = 0; i < 9; ++i){
    tests[i] = Cache(values[i]);
    tests[i].experiment();
    std::cout << tests[i].get_res_dir_test() << " | " << tests[i].get_res_rev_test()
      << " | " << tests[i].get_res_rand_test() << std::endl;
    tests[i].delete_arr();
  }

  // apple silicon 2 уровня кэша, первый = 128кб, второй = 8мб
  // 64kb < 128kb < 256kb << 512kb << 1Mb << 2mb << 4mb << 8mb << 12mb
//   16384;    // 64kb
//   32768;    // 128kb
//   65536;    // 256kb
//   131072;   // 512kb
//   262144;   // 1mb
//   len6 = 524288;   // 2mb
//   int len7 = 1048576;  // 4mb
//   int len8 = 2097152;  // 8mb
//   int len9 = 3145728;  // 12mb
}
