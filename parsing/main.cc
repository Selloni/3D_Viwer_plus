
#include "../Controller/s21_Controller.h"
#include "../Facade/s21_facade.h"


int main () {
  s21::Facade ff = s21::Facade::getInstance();
  std::string file_path = "obj/cub.obj";
  ff.SetPath(file_path);
  int indices_1[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
                     5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
                     0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
                     1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
  for (size_t i = 0; i < 72; i++) {
    std::cout << ff.GetArrFacets()[i]<< "  " <<indices_1[i]<< "\n";
  }
}
