#ifndef SRC_CONTROLLER_SRC_H_
#define SRC_CONTROLLER_SRC_H_
#include "../parsing/s21_viewer.h"
#include <vector>

class Controller {
  s21::Model model_;
  s21::Model::data_t obj;
  public:
  using unit = unsigned int;
  unit get_count_vertex() {return obj.count_vert;}
  unit get_count_facets() {return obj.count_facets;}
  double *get_arr_vertex() { return obj.vertexes;}
  unit *get_arr_facets() {return obj.facets;}
  bool set_find_file(std::string str) {
    return model_.s21_count_v_f(str, &obj);
  }
};


#endif // SRC_CONTROLLER_SRC_H_