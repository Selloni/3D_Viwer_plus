#ifndef SRC_FACADE_H_
#define SRC_FACADE_H_

//#include "../Controller/s21_controller.h"
#include "../parsing/s21_viewer.h"
// #include "../3DWieve/mainwindow.h"

namespace s21 {
using unit = unsigned int;

class Facade {
  private:
    // Controller controller_;
    Model model_;
  public:
    Facade() {}
    ~Facade(){}
    
//    static Facade& getInstance() {
//      static Facade instance;
//      return instance;
//    }

    // bool SetPath(std::string);
    // void FreeMemory();
    // void Scale(double scale);
    // unit GetCountVertex() {return controller_.obj.count_vert;}
    // unit GetCountFacets() { return controller_.obj.count_facets;}
    // double* GetArrVertex() {return controller_.obj.vertexes;}
    // unit* GetArrFacets() {return controller_.obj.facets;}

    // void Rotate(double scale, char direction);
    // void Move(double scale, char direction);
    void s21_rotate(double **vertex, char xyz, double angle, unint i);
    void s21_moveX(double **vertex, double move_x, unint count_v);
    void s21_moveY(double **vertex, double move_y, unint count_v);
    void s21_moveZ(double **vertex, double move_z, unint count_v);
    void s21_scale(double **vertex, float scale, unint count_v);
  
}; // Facade


} // s21

#endif // SRC_FACADE_H_
