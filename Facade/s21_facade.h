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
  void get_value(unit &qcount_vert, unit &qcount_facets, double &qvertexes, unit &qfacets);
  void free();
  
}; // Facade
} // s21

#endif // SRC_FACADE_H_