#ifndef SRC_CONTROLLER_S21_CONTROLLER_H_
#define SRC_CONTROLLER_S21_CONTROLLER_H_
#include "../parsing/s21_viewer.h"
#include "../Facade/s21_facade.h"
#include <vector>

namespace s21{
class Controller {
  // protected:
  public:
  s21::Model model_;
  s21::data_t obj;
  s21::Facade fasade_;
  Controller() {}
  ~Controller() {}
  bool set_path_file(std::string str) {
    return model_.s21_count_v_f(str, obj);
  }
  unint get_count_vertex() {return obj.count_vert;}
  unint get_count_facets() {return obj.count_facets;}
  double *get_arr_vertex() {return obj.vertexes;}
  unint *get_arr_facets() {return obj.facets;}
  void open(std::string str) {
    model_.s21_read(str, obj);
  }  
}; // Controller


} // s21

#endif // SRC_CONTROLLER_S21_CONTROLLER_H_
