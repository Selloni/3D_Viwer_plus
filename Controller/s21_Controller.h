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
  Controller() {}
  ~Controller() {
    // this->free();
  }
  bool set_path_file(std::string str) {
    return model_.s21_count_v_f(str, obj);
  }
  void free() {
    if (obj.facets != nullptr) {
      delete[] obj.facets;
        obj.count_facets = 0;
    }
    if (obj.count_vert) {
      delete[] obj.vertexes;
        obj.count_vert = 0;
    }
  }
  void open(std::string str) {
    model_.s21_read(str, obj);
  }
}; // Controller


} // s21

#endif // SRC_CONTROLLER_S21_CONTROLLER_H_
