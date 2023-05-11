#include "s21_facade.h"

bool s21::Facade::set_path(std::string str) {
  bool flag = controller_.set_path_file(str);
  if (!flag) controller_.open(str);
  return flag;  // 0 success
}

// void s21::Facade::get_value(unit &qcount_vert, unit &qcount_facets, double *qvertexes, unit *qfacets) {
//   qcount_vert = controller_.get_count_vertex();
//   qcount_facets = controller_.get_count_facets();
//   qvertexes = controller_.get_arr_vertex();
//   qfacets = controller_.get_arr_facets();
// }

void s21::Facade::free(){
  controller_.free();
}