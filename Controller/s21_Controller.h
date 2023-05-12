#ifndef SRC_CONTROLLER_S21_CONTROLLER_H_
#define SRC_CONTROLLER_S21_CONTROLLER_H_
#include "../parsing/s21_viewer.h"
#include <vector>

namespace s21{
class Controller {
  // protected:
  public:
  s21::Model model_;
  s21::data_t obj;
  bool set_path_file(std::string str) {
    return model_.s21_count_v_f(str, obj);
  }
  void free(){
    delete[] obj.facets;
    delete[] obj.vertexes;
  }
  void open(std::string str) {
    model_.s21_read(str, obj);
  }
}; // Controller


} // s21

#endif // SRC_CONTROLLER_S21_CONTROLLER_H_