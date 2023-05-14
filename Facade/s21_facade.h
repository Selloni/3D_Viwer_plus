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
    ~Facade(){}
    using unit = unsigned int;
    static Facade& getInstance() {
      static Facade instance;
      return instance;
    }
    // MainWindow MainWindow = new MainWindow();
    bool SetPath(std::string);
    void FreeMemory();
    void Scale(double scale);
    unit GetCountVertex() {return controller_.obj.count_vert;}
    unit GetCountFacets() { return controller_.obj.count_facets;}
    std::vector<double> GetArrVertex() {return controller_.obj.vertexes;}
    std::vector<unit> GetArrFacets() {return controller_.obj.facets;}
    // void fmove(s21::Strategy &move, double offset, char direction);

    void Rotate(double scale, char direction);
    void Move(double scale, char direction);
}; // Facade


} // s21

#endif // SRC_FACADE_H_
