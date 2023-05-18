#ifndef SRC_PARSING_S21_VIEWER_H_
#define SRC_PARSING_S21_VIEWER_H_

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace s21 {
typedef unsigned int unint;

struct data_t {
  unint count_vert = 0;    // количество v
  unint count_facets = 0;  // количество f
  double *vertexes = 0;    // хранятся в, цифры
  unint *facets = 0;  // массив, в нем полигоны, эфки 122331
};

class Model {
 public:
  ////parser
  bool s21_count_v_f(std::string file_name, data_t &obj);
  void s21_read(std::string file_name, data_t &obj);
  int s21_digit_supp(char ind);
  unint s21_space_for_Fsupp(std::string ch);
  unint s21_Fconnect(data_t &obj, std::string ch, unint index_f);
};
}  // namespace s21

#endif  // SRC_PARSING_S21_VIEWER_H_
