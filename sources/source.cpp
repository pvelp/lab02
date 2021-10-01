// Copyright 2020 Your Name <your_email>

#include <header.hpp>

Cache::Cache(int len): _len(len)
                        ,_result_direction_test(0)
                        ,_result_reverse_test(0)
                        ,_result_random_test(0)
{_arr = (int*)malloc(sizeof(int) * len);};

void Cache::filling() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<>dist(1, 10);
  for (int i = 0; i < _len; ++i){
    _arr[i] = dist(gen);
  }
}

void Cache::warming_up() {
  int k = 0;
  for (int i = 0; i < _len; i += 16) {
    k = _arr[i];
  }
}

void Cache::direction_test() {
  int k = 0;
  for (int i = 0; i < _len; i += 16) {
    k = _arr[i];
  }
}

void Cache::reverse_test() {
  int k = 0;
  for (int i = _len-1; i >= 0; i-=16){
    k = _arr[i];
  }
}

void Cache::random_test() {
}