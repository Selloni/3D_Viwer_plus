
#include "../Controller/s21_Controller.h"

int main () {
  Controller pp;
  // data_t obj;
  pp.set_find_file("../obj/cub.obj");
  pp.open("../obj/cub.obj");
  // std::string file_path = "../obj/cub.obj";
  // s21_count_v_f(file_path, &obj);
  // s21_read(file_path, &obj);
  double vertex[24] = {1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       -1.000000, -1.000000, 1.000000,  1.000000,  -0.999999,
                       0.999999,  1.000000,  1.000001,  -1.000000, 1.000000,
                       1.000000,  -1.000000, 1.000000,  -1.000000};
  // double tmp = pp.get_arr_facets();
  for (int i = 0; i < 24; i++) {
    std::cout << "my::" << pp.get_arr_vertex()[i] << "  test::" << vertex[i] << '\n';
  }
  for (int i = 0 ; i < 36*2; ++i) {
    std::cout << pp.get_arr_facets()[i];
  }
  // delete(obj.facets);
  // delete(obj.vertexes);
}
