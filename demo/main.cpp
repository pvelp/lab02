#include <header.hpp>

//
//void fill_array(int* arr, int len){
//  std::random_device rd;
//  std::mt19937 gen(rd());
//  std::uniform_int_distribution<>dist(1, 10);
//  for (int i = 0; i < len; ++i){
//    arr[i] = dist(gen);
//  }
//}


int main() {
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
//
//  [[maybe_unused]] int k = 0;
//  clock_t start;
//  double duration;
//  // 1  64kb = 2^16 byte => 2^14 = len = 4096
//  int arr1[16384];
//  fill_array(arr1, len1);
//  for (int i = 0; i < len1; i += 16) {
//    k = arr1[i];
//  }
//  start = clock();
//  for (int i = 0; i < 1000; i++) {
//    for (int j = 0; j < len1; j += 16) {
//      k = arr1[i];
//    }
//  }
//  duration = (double)(clock() - start) / CLOCKS_PER_SEC;
//  std::cout << "1 experiment: DIRECTION " << duration << "sec" << std::endl;
//
//  int arr2[32768];
//  fill_array(arr2, len2);
//  for (int i = 0; i < len2; i += 16) {
//    k = arr2[i];
//  }
//  start = clock();
//  for (int i = 0; i < 1000; i++) {
//    for (int j = 0; j < len2; j += 16) {
//      k = arr2[i];
//    }
//  }
//  duration = (double)(clock() - start) / CLOCKS_PER_SEC;
//  std::cout << "2 experiment: DIRECTION " << duration << "sec" << std::endl;
//
//  int arr3[65536];
//  fill_array(arr3, len3);
//  for (int i = 0; i < len3; i += 16) {
//    k = arr3[i];
//  }
//  start = clock();
//  for (int i = 0; i < 1000; i++) {
//    for (int j = 0; j < len3; j += 16) {
//      k = arr3[i];
//    }
//  }
//  duration = (double)(clock() - start) / CLOCKS_PER_SEC;
//  std::cout << "3 experiment: DIRECTION " << duration << "sec" << std::endl;
//
//  int arr4[131072];
//  fill_array(arr4, len4);
//  for (int i = 0; i < len4; i += 16) {
//    k = arr4[i];
//  }
//  start = clock();
//  for (int i = 0; i < 1000; i++) {
//    for (int j = 0; j < len4; j += 16) {
//      k = arr4[i];
//    }
//  }
//  duration = (double)(clock() - start) / CLOCKS_PER_SEC;
//  std::cout << "4 experiment: DIRECTION " << duration << "sec" << std::endl;
//
//  int arr5[262144];
//  fill_array(arr5, len5);
//  for (int i = 0; i < len5; i += 16) {
//    k = arr5[i];
//  }
//  start = clock();
//  for (int i = 0; i < 1000; i++) {
//    for (int j = 0; j < len5; j += 16) {
//      k = arr5[i];
//    }
//  }
//  duration = (double)(clock() - start) / CLOCKS_PER_SEC;
//  std::cout << "5 experiment: DIRECTION " << duration << "sec" << std::endl;
//
//  int arr6[524288];
//  fill_array(arr6, len6);
//  for (int i = 0; i < len6; i += 16) {
//    k = arr6[i];
//  }
//  start = clock();
//  for (int i = 0; i < 1000; i++) {
//    for (int j = 0; j < len6; j += 16) {
//      k = arr6[i];
//    }
//  }
//  duration = (double)(clock() - start) / CLOCKS_PER_SEC;
//  std::cout << "6 experiment: DIRECTION " << duration << "sec" << std::endl;
//
//  int arr7[1048576];
//  fill_array(arr7, len7);
//  for (int i = 0; i < len7; i += 16) {
//    k = arr7[i];
//  }
//  start = clock();
//  for (int i = 0; i < 1000; i++) {
//    for (int j = 0; j < len7; j += 16) {
//      k = arr7[i];
//    }
//  }
//  duration = (double)(clock() - start) / CLOCKS_PER_SEC;
//  std::cout << "7 experiment: DIRECTION " << duration << "sec" << std::endl;
//
//    int arr8[2097152];
//    fill_array(arr8, len8);
//    for (int i = 0; i < len8; i += 16){
//      k = arr8[i];
//    }
//    start = clock();
//    for (int i = 0; i < 1000; i++){
//      for (int j = 0; j < len8; j += 16){
//        k = arr8[i];
//      }
//    }
//    duration = (double)(clock()-start) / CLOCKS_PER_SEC;
//    std::cout <<"8 experiment: DIRECTION "<< duration << "sec" << std::endl;
  //
  //  int arr9[3145728];
  //  fill_array(arr9, len9);
  //  for (int i = 0; i < len9; i += 16){
  //    k = arr9[i];
  //  }
  //  start = clock();
  //  for (int i = 0; i < 1000; i++){
  //    for (int j = 0; j < len9; j += 16){
  //      k = arr9[i];
  //    }
  //  }
  //  duration = (double)(clock()-start) / CLOCKS_PER_SEC;
  //  std::cout <<"9 experiment: DIRECTION "<< duration << "sec" << std::endl;
  //
//  int *arr1;
//  arr1 = (int*)malloc(len1 * sizeof(int));
//  std::cout << sizeof (arr1);
}
