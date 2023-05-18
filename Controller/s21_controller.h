#ifndef SRC_CONTROLLER_S21_CONTROLLER_H_
#define SRC_CONTROLLER_S21_CONTROLLER_H_
#include <vector>

#include "../Facade/s21_facade.h"
#include "../parsing/s21_viewer.h"

namespace s21 {
class Controller {
  // protected:
 public:
  s21::Model model;
  s21::data_t obj;
  s21::Facade fasade;
  Controller() {}
  ~Controller() {}
  bool SetPathFile(std::string str) { return model.s21CountVF(str, obj); }
  unint GetCountVertex() { return obj.count_vert; }
  unint GetCountFacets() { return obj.count_facets; }
  double *GetArrVertex() { return obj.vertexes; }
  unint *GetArrFacets() { return obj.facets; }
  void Open(std::string str) { model.s21Read(str, obj); }
};  // Controller

}  // namespace s21

#endif  // SRC_CONTROLLER_S21_CONTROLLER_H_
