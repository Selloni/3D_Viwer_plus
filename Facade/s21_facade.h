#ifndef SRC_FACADE_H_
#define SRC_FACADE_H_

#include "../Controller/s21_controller.h"
// #include "../3DWieve/mainwindow.h"

namespace s21 {
class Facade {
  public:
  using unit = unsigned int;
  Controller controller_;
  // MainWindow maintwindow_;
  bool set_path(std::string);
  unit get_count_vertex() {return controller_.obj.count_vert;}
  unit get_count_facets() {return controller_.obj.count_facets;}
  double *get_arr_vertex() {return controller_.obj.vertexes;}
  unit *get_arr_facets() {return controller_.obj.facets;}
  void free();
}; // Facade
} // s21

#endif // SRC_FACADE_H_