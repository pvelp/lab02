// Copyright 2021 pvelp <toschakovpv@yandex.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cassert>
#include <cmath>


class Cache{
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


 public:
  explicit Cache(int len);
  void experiment();
  [[nodiscard]]double  get_res_dir_test() const;
  [[nodiscard]]double get_res_rev_test() const;
  [[nodiscard]]double get_res_rand_test() const;
  void delete_arr();

//  void print_results();
};

void shuffle(int *array, size_t n);

#endif // INCLUDE_HEADER_HPP_
