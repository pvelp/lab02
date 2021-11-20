// Copyright 2021 pvelp <toschakovpv@yandex.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <ctime>
#include <random>
#include <cassert>
#include <cmath>


class Cache {
 private:
  int *_arr;
  int _len;
  double _result_direction_test;
  double _result_reverse_test;
  double _result_random_test;
  void filling();
  void warming_up();
  void direction_test();
  void reverse_test();
  void random_test();
  const int step = 16;
  const int num_of_steps = 1000;

 public:
  explicit Cache(int len);
  void experiment();
  [[nodiscard]] double get_res_dir_test() const;
  [[nodiscard]] double get_res_rev_test() const;
  [[nodiscard]] double get_res_rand_test() const;
  void delete_arr();
};

void shuffle(int *array, size_t n);
int count(const int a, const int b);
void filling_arr(int *arr, const int& size, int& val);
void print(int *arr, const int& size, std::ostream &os1);

#endif // INCLUDE_HEADER_HPP_
