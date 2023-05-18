#ifndef SRC_FACADE_H_
#define SRC_FACADE_H_

#include "../Controller/s21_controller.h"
// #include "../3DWieve/mainwindow.h"

namespace s21 {
class Facade {
  private:
    Controller controller_;

  public:
    Facade() {}
    // ~Facade(){this->free();}
    using unit = unsigned int;
    static Facade& getInstance() {
      static Facade instance;
      return instance;
    }
    // MainWindow MainWindow = new MainWindow();
    bool set_path(std::string);
    void free();
    unit get_count_vertex() {return controller_.obj.count_vert;}
    unit get_count_facets() { return controller_.obj.count_facets;}
    double *get_arr_vertex() {return controller_.obj.vertexes;}
    unit *get_arr_facets() {return controller_.obj.facets;}
    void fmove(s21::Strategy &move, double offset, char direction);
}; // Facade
} // s21

#endif // SRC_FACADE_H_
