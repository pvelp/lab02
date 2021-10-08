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

//
//  auto test1 = Cache(16384); //64kb
//  test1.experiment();
//  auto test2 = Cache(32768); //128kb
//  test2.experiment();
//  auto test3 = Cache(65536); //132kb
//  test3.experiment();
//  auto test4 = Cache(131072);
//  test4.experiment();
//  auto test5 = Cache(262144);
//  test5.experiment();
//  auto test6 = Cache(524288);
//  test6.experiment();
//  auto test7 = Cache(1048576);
//  test7.experiment();
//  auto test8 = Cache(2097152);
//  test8.experiment();
//  auto test9 = Cache(3145728);
//  test9.experiment();
//  std::cout << test1.get_res_dir_test() << " | " << test1.get_res_rev_test()
//  << " | " << test1.get_res_rand_test() << std::endl;
//  std::cout << test2.get_res_dir_test() << " | " << test2.get_res_rev_test()
//            << " | " << test2.get_res_rand_test() << std::endl;
//  std::cout << test3.get_res_dir_test() << " | " << test3.get_res_rev_test()
//            << " | " << test3.get_res_rand_test() << std::endl;
//  std::cout << test4.get_res_dir_test() << " | " << test4.get_res_rev_test()
//            << " | " << test4.get_res_rand_test() << std::endl;
//  std::cout << test5.get_res_dir_test() << " | " << test5.get_res_rev_test()
//            << " | " << test5.get_res_rand_test() << std::endl;
//  std::cout << test6.get_res_dir_test() << " | " << test6.get_res_rev_test()
//            << " | " << test6.get_res_rand_test() << std::endl;
//  std::cout << test7.get_res_dir_test() << " | " << test7.get_res_rev_test()
//            << " | " << test7.get_res_rand_test() << std::endl;
//  std::cout << test8.get_res_dir_test() << " | " << test8.get_res_rev_test()
//            << " | " << test8.get_res_rand_test() << std::endl;
//  std::cout << test9.get_res_dir_test() << " | " << test9.get_res_rev_test()
//            << " | " << test9.get_res_rand_test() << std::endl;




  // apple silicon 2 уровня кэша, первый = 128кб, второй = 8мб
  // 64kb < 128kb < 256kb << 512kb << 1Mb << 2mb << 4mb << 8mb << 12mb
//  [[maybe_unused]] int len1 = 16384;    // 64kb
//  [[maybe_unused]] int len2 = 32768;    // 128kb
//  [[maybe_unused]] int len3 = 65536;    // 256kb
//  [[maybe_unused]] int len4 = 131072;   // 512kb
//  [[maybe_unused]] int len5 = 262144;   // 1mb
//  [[maybe_unused]] int len6 = 524288;   // 2mb
//  [[maybe_unused]] int len7 = 1048576;  // 4mb
//  [[maybe_unused]] int len8 = 2097152;  // 8mb
//  [[maybe_unused]] int len9 = 3145728;  // 12mb
}
