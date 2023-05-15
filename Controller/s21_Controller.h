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
  ~Controller() {
    // this->free();
  }
  bool set_path_file(std::string str) {
    return model_.s21_count_v_f(str, obj);
  }
  //  void free() {
  //    if (!obj.facets.empty()) {
  //      obj.facets.clear();
  //      obj.count_facets = 0;
  //    }
  //    if (!obj.vertexes.empty()) {
  //      obj.vertexes.clear();
  //      obj.count_vert = 0;
  //    }
  //    std::cout << "free()" << "\n";
  //  }
  void open(std::string str) {
    model_.s21_read(str, obj);
  }

 void s21_rotate(double **vertex, char xyz, double angle, unint i) {
     fasade_.s21_rotate(vertex, xyz, angle, i);
 }
 void s21_moveX(double **vertex, double move_x, unint count_v){
     fasade_.s21_moveX(vertex, move_x, count_v);
 }
 void s21_moveY(double **vertex, double move_y, unint count_v){
     fasade_.s21_moveY(vertex, move_y, count_v);
 }
 void s21_moveZ(double **vertex, double move_z, unint count_v){
     fasade_.s21_moveZ(vertex, move_z, count_v);
 }
 void s21_scale(double **vertex, float scale, unint count_v){
     fasade_.s21_scale(vertex, scale, count_v);
 }
  
}; // Controller


} // s21

#endif // SRC_CONTROLLER_S21_CONTROLLER_H_
