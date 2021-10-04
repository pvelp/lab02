// Copyright 2020 Your Name <your_email>

#include <header.hpp>

Cache::Cache(int len): _len(len)
                        ,_result_direction_test(0)
                        ,_result_reverse_test(0)
                        ,_result_random_test(0)
{_arr = (int*)malloc(sizeof(int) * len);}

void Cache::filling() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<>dist(1, 10);
  for (int i = 0; i < _len; ++i){
    _arr[i] = dist(gen);
  }
}

void Cache::warming_up() {
  [[maybe_unused]]int k = 0;
  for (int i = 0; i < _len; i += 16) {
    k = _arr[i];
  }
}

void Cache::direction_test() {
  [[maybe_unused]]int k = 0;
  for (int i = 0; i < _len; i += 16) {
    k = _arr[i];
  }
}

void Cache::reverse_test() {
  [[maybe_unused]]int k = 0;
  for (int i = _len-1; i >= 0; i-=16){
    k = _arr[i];
  }
}

void Cache::random_test() {
  [[maybe_unused]]int k = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<>dist(1, _len);
  for (int i = 0; i < _len; i += dist(gen) / 16 + (dist(gen) % 16)){
    k = _arr[i];
  }
}

void Cache::experiment() {
  this->filling();
  clock_t start1;
  clock_t start2;
  clock_t start3;
  this->warming_up();

  start1 = clock();
  for (int i = 0; i < 1000; ++i){
    this->direction_test();
  }
  _result_direction_test = (double)(clock() - start1) / CLOCKS_PER_SEC;

  start2 = clock();
  for (int i = 0; i < 1000; ++i){
    this->reverse_test();
  }
  _result_reverse_test = (double)(clock() - start2) / CLOCKS_PER_SEC;

  start3 = clock();
  for (int i = 0; i < 1000; ++i){
    this->random_test();
  }
  _result_random_test = (double)(clock() - start3) / CLOCKS_PER_SEC;
}

double Cache::get_res_dir_test() {
  return _result_direction_test;
}
double Cache::get_res_rev_test() {
  return _result_reverse_test;
}
double Cache::get_res_rand_test() {
  return _result_random_test;
}
