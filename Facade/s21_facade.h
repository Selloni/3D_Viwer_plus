#ifndef SRC_FACADE_H_
#define SRC_FACADE_H_

#include "../Controller/s21_controller.h"
// #include "../3DWieve/mainwindow.h"

namespace s21 {
class Facade {
  public:
  Controller controller_;
  // MainWindow MainWindow = new MainWindow();
  bool set_path(std::string);

}; // Facade
} // s21

#endif // SRC_FACADE_H_