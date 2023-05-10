#ifndef SRC_CONTROLLER_SRC_H_
#define SRC_CONTROLLER_SRC_H_
#include "../parsing/s21_viewer.h"

class Controller {
  using unit = unsigned int;
  unit get_count_vertex {};
  unit get_count_facets {};
  long double get_arr_vertex {};
  unit get_arr_facets {};
  bool set_find_file(std::string str) {
    return bool s21_count_v_f(str,  *obj);
  }
};


#endif // SRC_CONTROLLER_SRC_H_