// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cassert>


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
  Cache(int len);
  void experiment();
  double get_res_dir_test();
  double get_res_rev_test();
  double get_res_rand_test();
//  void print_results();
};


//void print_result(Cache val1){
//  std::string res = R"(investigaion:
//travel_order: "direction"
//  experiments:
//    -experiment:
//      number: 1
//    input_data:
//      buffer_size: "1mb"
//    results:
//      duration: )";
//}

#endif // INCLUDE_HEADER_HPP_
//  investigaion:
//    travel_order: "direction"
//      experiments:
//        -experiment:
//          number: 1
//        input_data:
//          buffer_size: "1mb"
//        results:
//          duration: "1ns"