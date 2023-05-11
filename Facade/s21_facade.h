#ifndef SRC_FACADE_H_
#define SRC_FACADE_H_

#include "../Controller/s21_controller.h"
// #include "../3DWieve/mainwindow.h"

namespace s21 {
class Facade {
  private:
    Facade() {}

    Controller controller_;
  public:
    static Facade& getInstance() {
      static Facade instance;
      return instance;
    }
    // MainWindow MainWindow = new MainWindow();
    bool set_path(std::string);
    void free();

}; // Facade
} // s21

#endif // SRC_FACADE_H_