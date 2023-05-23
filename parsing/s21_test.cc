#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../Controller/s21_controller.h"
#include "../Transform/s21_transform.h"
#include "s21_viewer.h"

TEST(testOpen, 1) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.SetPathFile(file_path)) {
    double vertex[24] = {1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                         1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                         -1.000000, -1.000000, 1.000000,  1.000000,  -0.999999,
                         0.999999,  1.000000,  1.000001,  -1.000000, 1.000000,
                         1.000000,  -1.000000, 1.000000,  -1.000000};
    for (int i = 0; i < 24; i++) {
      // std::cout << controller_.GetArrVertex()[i] << " " << vertex[i] <<
      // std::endl;
      ASSERT_EQ(controller_.GetArrVertex()[i], vertex[i]);
    }
  }
}

TEST(testOpen, 2) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.SetPathFile(file_path)) {
    int indices_1[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
                       5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
                       0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
                       1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
    for (size_t i = 0; i < 72; i++) {
      ASSERT_EQ(controller_.obj.facets[i], indices_1[i]);
    }
  }
}

TEST(testCountVertex, 1) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.SetPathFile(file_path)) {
    ASSERT_EQ(controller_.obj.count_vert, 8);
  }
}

TEST(testCountFacets, 2) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.SetPathFile(file_path)) {
    ASSERT_EQ(controller_.obj.count_facets, 36);
  }
}

TEST(testOpen, 3) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.SetPathFile(file_path)) {
    int indices_1[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
                       5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
                       0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
                       1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
    for (size_t i = 0; i < 72; i++) {
      ASSERT_EQ(controller_.obj.facets[i], indices_1[i]);
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
