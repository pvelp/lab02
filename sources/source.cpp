// Copyright 2021 pvelp <toschakovpv@yandex.ru>

#include <header.hpp>

Cache::Cache(int len): _len(len)
                        , _result_direction_test(0)
                        , _result_reverse_test(0)
                        , _result_random_test(0){}
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
  for (int i = 0; i < _len; i += step) {
    k = _arr[i];
  }
}

void Cache::direction_test() {
  [[maybe_unused]]int k = 0;
  clock_t start;
  start = clock();
  for (int j = 0; j < num_of_steps; ++j){
    for (int i = 0; i < _len; i += step) {
      k = _arr[i];
    }
  }
  double res = static_cast <double>(clock() - start) / CLOCKS_PER_SEC;
  _result_direction_test = res;
}

void Cache::reverse_test() {
  [[maybe_unused]]int k = 0;
  clock_t start;
  start = clock();
  for (int j = 0; j < num_of_steps; ++j){
    for (int i = _len-1; i >= 0; i-=step){
      k = _arr[i];
    }
  }
  _result_reverse_test = static_cast <double>(clock() - start) / CLOCKS_PER_SEC;
}

void shuffle(int *array, size_t n)
{
  if (n > 1)
  {
    size_t i;
    for (i = 0; i < n - 1; i++)
    {
      std::mt19937 gen(time(nullptr));
      std::uniform_int_distribution<> uid(0, n);
      size_t j = uid(gen);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

void Cache::random_test() {
   int* val = reinterpret_cast<int*>(malloc(sizeof (int) * (_len/16)));
  for (int i = 0; i < _len; i+=step){
    val[i] = i;
  }
  [[maybe_unused]]int k;
  shuffle(val, _len/step);
  clock_t start;
  start = clock();
  for (int j = 0; j < num_of_steps; ++j){
    for (int i = 0; i < _len; ++i){
      k = _arr[val[i]];
    }
  }
    double res = static_cast <double>(clock() - start) / CLOCKS_PER_SEC;
    _result_random_test = res;
}

void Cache::experiment() {
  _arr = reinterpret_cast<int*>(malloc(sizeof(int) * _len));
  filling();
  warming_up();
  direction_test();
  reverse_test();
  random_test();
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
  delete(_arr);
}

int count(const int a, const int b) {
  int res = 0;
  for (int i = a/2; i <= 3/2 * b; i*=2){
    res++;
  }
  return res;
}
void filling_arr(int *arr, const int& size, int& val){
  for (int i = 0; i < size; ++i){
    arr[i] = pow(2, val)/4;
    val++;
  }
}
void print(int *arr, const int& size, std::ostream &os1){ //std::ostream &os2,
  os1 << "- investigation:\n";
  os1 << "- travel_variant: direction\n\t";

  for (int i = 0; i < size+1; ++i) {
    auto tmp = Cache(arr[i]);
    tmp.experiment();
    os1 << "- experiment:\n\t\t - number: " << i
        << "\n\t\t - input_data: \n\t\t\t- buffer_size: " << arr[i]
        << "byte\n\t\t - results:\n\t\t\t - duration: "
        << round(tmp.get_res_dir_test() * 1000) << "ms \n\t";
    tmp.delete_arr();
  }

  os1<< "\n";
  os1 << "- investigation:\n";
  os1 << "- travel_variant: reverse\n\t";
  for (int i = 0; i < size+1; ++i) {
    auto tmp = Cache(arr[i]);
    tmp.experiment();
    os1 << "- experiment:\n\t\t - number: " << i
        << "\n\t\t - input_data: \n\t\t\t- buffer_size: " << arr[i]
        << "byte\n\t\t - results:\n\t\t\t - duration: "
        << round(tmp.get_res_rev_test() * 1000) << "ms \n\t";
    tmp.delete_arr();
  }
  os1<< "\n";
  os1 << "- investigation:\n";
  os1 << "- travel_variant: random\n\t";
  for (int i = 0; i < size+1; ++i) {
    auto tmp = Cache(arr[i]);
    tmp.experiment();
    os1 << "- experiment:\n\t\t - number: " << i
        << "\n\t\t - input_data: \n\t\t\t- buffer_size: " << arr[i]
        << "byte\n\t\t - results:\n\t\t\t - duration: "
        << round(tmp.get_res_rand_test() * 1000) << "ms \n\t";
    tmp.delete_arr();
  }
}
