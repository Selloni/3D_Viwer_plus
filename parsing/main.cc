
#include "../Controller/s21_Controller.h"
#include "../Facade/s21_facade.h"


int main () {

  std::string file_path = "obj/cub.obj";
  s21::Facade ff = s21::Facade::getInstance();
  // s21::Facade ff;
  ff.set_path(file_path);
    double vertex[24] = {1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       -1.000000, -1.000000, 1.000000,  1.000000,  -0.999999,
                       0.999999,  1.000000,  1.000001,  -1.000000, 1.000000,
                       1.000000,  -1.000000, 1.000000,  -1.000000};
  for (int i = 0; i < 24; i++) {
    std::cout << ff.get_arr_vertex()[i] << vertex[i]  << "\n";
  }
  // delete(obj.facets);
  // delete(obj.vertexes);

}
