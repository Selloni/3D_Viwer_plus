
#include "../Controller/s21_Controller.h"
#include "../Facade/s21_facade.h"


int main () {
  unsigned int count_vert;
  unsigned int count_facets;
  double *vertexes;
  unsigned int *facets;
  std::string file_path = "obj/cub.obj";
  s21::Facade ff;
  s21::Controller pp;
  // data_t obj;
  pp.set_path_file("../obj/cub.obj");
  pp.open("../obj/cub.obj");
  // ff.set_path(file_path);
  // ff.get_value(count_vert,count_facets, vertexes, facets);
  count_vert = ff.controller_.get_count_vertex();
  count_facets =ff.controller_.get_count_facets();
  vertexes = ff.controller_.get_arr_vertex();
  facets = ff.controller_.get_arr_facets();
  // cc.set_path_file(file_path);
  // facets = cc.get_arr_facets();
  // vertexes = cc.get_arr_vertex();
  // pp.get_value(count_vert,count_facets, vertexes, facets);
  double vertex[24] = {1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       -1.000000, -1.000000, 1.000000,  1.000000,  -0.999999,
                       0.999999,  1.000000,  1.000001,  -1.000000, 1.000000,
                       1.000000,  -1.000000, 1.000000,  -1.000000};
  for (int i = 0; i < 24; i++) {
    std::cout << "my::" << pp.get_arr_vertex()[i] << "  test::" << vertex[i] << '\n';;
  }
}
