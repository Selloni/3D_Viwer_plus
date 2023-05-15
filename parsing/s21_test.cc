#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "s21_viewer.h"
#include "../Controller/s21_controller.h"
#include "../Facade/s21_facade.h"

TEST(test_open, 1) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.set_path_file(file_path)) {
    double vertex[24] = {1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       -1.000000, -1.000000, 1.000000,  1.000000,  -0.999999,
                       0.999999,  1.000000,  1.000001,  -1.000000, 1.000000,
                       1.000000,  -1.000000, 1.000000,  -1.000000};
    for (int i = 0; i < 24; i++) {
      // std::cout << controller_.get_arr_vertex()[i] << " " << vertex[i] << std::endl;
      ASSERT_EQ(controller_.get_arr_vertex()[i], vertex[i]);
    }
  }
}

TEST(test_open, 2) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.set_path_file(file_path)) {
    int indices_1[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
                      5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
                      0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
                      1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
    for (size_t i = 0; i < 72; i++) {
      ASSERT_EQ(controller_.obj.facets[i], indices_1[i]);
    }
  }
}

TEST(test_count_vert, 1) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.set_path_file(file_path)) {
    ASSERT_EQ(controller_.obj.count_vert, 8);
  }
}

TEST(test_count_facets, 2) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.set_path_file(file_path)) {
    ASSERT_EQ(controller_.obj.count_facets, 36);
  }
}

TEST(test_open, 3) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.set_path_file(file_path)) {
    int indices_1[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
                      5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
                      0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
                      1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
    for (size_t i = 0; i < 72; i++) {
      ASSERT_EQ(controller_.obj.facets[i], indices_1[i]);
    }
  }
}

TEST(moveX, 3) {
  s21::Controller controller_;
  std::string file_path = "obj/cub.obj";
  if (controller_.set_path_file(file_path)) {
    s21::Move move_;
    controller_.fasade_.transform(move_, &controller_.obj.vertexes, 'x', 0.9, controller_.obj.count_vert);
    // ff.Move(0.9, 'x');
    // mv.s21_move(&obj.vertexes, 0.9, obj.count_vert * 3, 'x');
    double vertex_1[] = {1.900000,  -1.000000, -1.000000, 1.900000,  -1.000000,
                        1.000000,  -0.100000, -1.000000, 1.000000,  -0.100000,
                        -1.000000, -1.000000, 1.900000,  1.000000,  -0.999999,
                        1.899999,  1.000000,  1.000001,  -0.100000, 1.000000,
                        1.000000,  -0.100000, 1.000000,  -1.000000}; 
    for (size_t i = 0; i < 24; i++) {
      ASSERT_NEAR(controller_.obj.vertexes[i], vertex_1[i], 1e-6);
    }
  }
}

// TEST(test_4_copy, 4) {
//   s21::Facade ff = s21::Facade::getInstance();
//   std::string file_path = "obj/cub.obj";
//   ff.SetPath(file_path);
//   ff.Move(-1.4, 'y');
  
//   // mv.s21_move(&obj.vertexes, -1.4, obj.count_vert * 3, 'y');
//   double vertex_1[] = {-1.300000,  -1.000000, -1.000000, -1.300000,  -1.000000,
//                        1.000000,  -3.300000, -1.000000, 1.000000,  -3.300000,
//                        -1.000000, -1.000000, -1.300000,  1.000000, -0.999999,
//                        -1.300000, 1.000000, 1.000001,  -3.300000, 1.000000,
//                        1.000000,  -3.300000, 1.000000, -1.000000};
//   for (size_t i = 0; i < 24; i++) {
//     // std::cout << ff.GetArrVertex()[i] << " = " << vertex_1[i] << std::endl;
//     ASSERT_NEAR(ff.GetArrVertex()[i], vertex_1[i], 1e-6);
//   }
// }

// // Не рабочий тест
// TEST(test_5, 5) {
//   s21::Facade ff = s21::Facade::getInstance();
//   std::string file_path = "obj/cub.obj";
//   ff.SetPath(file_path);
//   ff.Move(0.9, 'x');
//   // mv.s21_move(&obj.vertexes, 0.9, obj.count_vert * 3, 'x');
//   double vertex_1[] = {3.300000,  -1.000000, -1.000000, 3.300000,  -1.000000,
//                        1.000000,  1.300000, -1.000000, 1.000000,  1.300000,
//                        -1.000000, -1.000000, 3.300000,  1.000000,  -0.999999,
//                        3.300000,  1.000000,  1.000001,  1.300000, 1.000000,
//                        1.000000,  1.300000, 1.000000,  -1.000000};
//   for (size_t i = 0; i < 24; i++) {
//     // std::cout << ff.GetArrVertex()[i] << " = " << vertex_1[i] << std::endl;
//     ASSERT_NEAR(ff.GetArrVertex()[i], vertex_1[i], 1e-2);
//   }
// }

// TEST(scale, 6) {
//   s21::Facade ff = s21::Facade::getInstance();
//   std::string file_path = "obj/cub.obj";
//   ff.SetPath(file_path);
//   ff.Scale(2.3);
//   // sc.s21_move(&obj.vertexes, 2.3, obj.count_vert * 3);
//   double vertex_1[] = {2.300000,  -2.300000, -2.300000, 2.300000,  -2.300000,
//                        2.300000,  -2.300000, -2.300000, 2.300000,  -2.300000,
//                        -2.300000, -2.300000, 2.300000,  2.300000,  -2.299998,
//                        2.299998,  2.300000,  2.300002,  -2.300000, 2.300000,
//                        2.300000,  -2.300000, 2.300000,  -2.300000};
//   for (size_t i = 0; i < 24; i++) {
//     ASSERT_NEAR(ff.GetArrVertex()[i], vertex_1[i], 1e-6);
//   } 
// }

// TEST(rotate, 7) {
//   s21::Facade ff = s21::Facade::getInstance();
//   std::string file_path = "obj/cub.obj";
//   ff.SetPath(file_path);
//   ff.Rotate(2.3, 'z');
//   // sc.s21_move(&obj.vertexes, 2.3, obj.count_vert * 3);
//   double vertex_1[] = {0.0794292,  1.41198, -1.00000, 0.0794292,  1.41198,
//                        1.000000,  1.41198, -0.0794292, 1.000000,  1.41198,
//                       -0.0794292, -1.000000, -1.41198,  0.0794292,  -0.999999,
//                        -1.41198,  0.0794284,  1.000002,  -0.0794292, -1.41198,
//                        1.000000,  -0.0794292, -1.41198,  -1.000000};
//   for (size_t i = 0; i < 24; i++) {
//     // std::cout << ff.GetArrVertex()[i] << " = " << vertex_1[i] << std::endl;
//     ASSERT_NEAR(ff.GetArrVertex()[i], vertex_1[i], 0.01);
//   }
// }

// // TEST(MoveTest, MoveX) {
// //   s21::Move move;
// //   s21::Model::data_t obj;
// //   obj.count_vert = 3;
// //   obj.vertexes = new double[9] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
// //   double expected[9] {2.0, 2.0, 3.0, 5.0, 5.0, 6.0, 8.0, 8.0, 9.0};

// //   move.s21_move(&obj.vertexes, 1.0, obj.count_vert, 'x');

// //   for (int i = 0; i < 9; ++i) {
// //     EXPECT_DOUBLE_EQ(obj.vertexes[i], expected[i]);
// //   }
// //   delete[] obj.vertexes;
// // }


// // TEST(ScaleTest, Scale) {
// //   s21::Scale scale;
// //   s21::Model::data_t obj;
// //   obj.count_vert = 3;
// //   obj.vertexes = new double[9] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
// //   double expected[9] {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0};

// //   // Act
// //   scale.s21_move(&obj.vertexes, 2.0, obj.count_vert);

// //   // Assert
// //   for (int i = 0; i < 9; ++i) {
// //     EXPECT_DOUBLE_EQ(obj.vertexes[i], expected[i]);
// //   }
// //   delete[] obj.vertexes;
// // }

// // TEST(MoveTest, MoveX) {
// //   s21::Move move;
// //   s21::Model::data_t obj;
// //   obj.count_vert = 3;
// //   obj.vertexes = new double[9] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
// //   double expected[9] {2.0, 2.0, 3.0, 5.0, 5.0, 6.0, 8.0, 8.0, 9.0};

// //   move.s21_move(&obj.vertexes, 1.0, obj.count_vert, 'x');

// //   for (int i = 0; i < 9; ++i) {
// //     EXPECT_DOUBLE_EQ(obj.vertexes[i], expected[i]);
// //   }
// //   delete[] obj.vertexes;
// // }


// // TEST(ScaleTest, Scale) {
// //   s21::Controller cc;
// //   cc.obj.vertexes = new double[9] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
// //   double expected[9] {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0};

// //   // Act
// //   scale.s21_move(&obj.vertexes, 2.0, obj.count_vert);

// //   // Assert
// //   for (int i = 0; i < 9; ++i) {
// //     EXPECT_DOUBLE_EQ(obj.vertexes[i], expected[i]);
// //   }
// //   delete[] obj.vertexes;
// // }

// TEST(Rotate, 2) {
//   s21::Facade ff = s21::Facade::getInstance();
//   std::string file_path = "obj/cub.obj";
//   ff.SetPath(file_path);
//   ff.Rotate(1.1, 'x');
//   ff.Rotate(1.1, 'y');
//   ff.Rotate(1.1, 'z');
//   double vertex_1[] = {-0.727887, -0.465364, -1.501205, 1.227345, -0.553322,
//                        -1.089706, 0.815846,  -1.361819, 0.692709, -1.139386,
//                        -1.273860, 0.281210,  -0.815845, 1.361819, -0.692708,
//                        1.139387,  1.273860,  -0.281209, 0.727887, 0.465364,
//                        1.501205,  -1.227345, 0.553322,  1.089706};
//   for (size_t i = 0; i < 24; i++) {
//     ASSERT_NEAR(ff.GetArrVertex()[i], vertex_1[i], 1e-6);
//   }
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}