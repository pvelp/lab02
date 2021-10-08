// Copyright 2021 pvelp <toschakovpv@yandex.ru>

#include <header.hpp>

Cache::Cache(int len): _len(len)
                        ,_result_direction_test(0)
                        ,_result_reverse_test(0)
                        ,_result_random_test(0){}
void Cache::filling() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<>dist(1, 10);
  for (int i = 0; i < this->_len; ++i){
    _arr[i] = dist(gen);
  }
}

void Cache::warming_up() {
  [[maybe_unused]]int k = 0;
  for (int i = 0; i < this->_len; i += 16) {
    k = _arr[i];
  }
}

void Cache::direction_test() {
  [[maybe_unused]]int k = 0;
  clock_t start;
  start = clock();
  for (int j = 0; j < 1000; ++j){
    for (int i = 0; i < this->_len; i += 16) {
      k = _arr[i];
    }
  }
  _result_direction_test = (double)(clock() - start) / CLOCKS_PER_SEC;
}

void Cache::reverse_test() {
  [[maybe_unused]]int k = 0;
  clock_t start;
  start = clock();
  for (int j = 0; j < 1000; ++j){
    for (int i = this->_len-1; i >= 0; i-=16){
      k = _arr[i];
    }
  }
  _result_reverse_test = (double)(clock() - start) / CLOCKS_PER_SEC;
}

void shuffle(int *array, size_t n)
{
  if (n > 1)
  {
    size_t i;
    for (i = 0; i < n - 1; i++)
    {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

void Cache::random_test() {
  int* val = (int*)malloc(sizeof (int) * (_len/16));
  for (int i = 0; i < _len; i+=16){
    val[i] = i;
  }
  [[maybe_unused]]int k;
  shuffle(val, _len/16);
  clock_t start;
  start = clock();
  for (int j = 0; j < 1000; ++j){
    for (int i = 0; i < this->_len; ++i){
      k = _arr[val[i]];
    }
  }
    _result_random_test = (double) (clock() - start) / CLOCKS_PER_SEC;
}

void Cache::experiment() {
  this->_arr = (int*)malloc(sizeof(int) * this->_len);
  this->filling();
  this->warming_up();
  this->direction_test();
  this->reverse_test();
  this->random_test();
}

double Cache::get_res_dir_test() const {
  return _result_direction_test;
}
double Cache::get_res_rev_test() const {
  return _result_reverse_test;
}
double Cache::get_res_rand_test() const{
  return _result_random_test;
}

void Cache::delete_arr() {
  delete(this->_arr);
}