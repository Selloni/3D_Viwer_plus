#include <gtest/gtest.h>
#include "s21_viewer.h"
#include "../Facade/s21_facade.h"
  // s21::Model pp;

using unit = unsigned int;
unit count_vert;
unit count_facets;
double *vertexes;
unit *facets;


TEST(test_open, 1) {
  s21::Model model;
  s21::Model::data_t obj;
  std::string file_path = "obj/cub.obj";
  s21::Facade ff;
  ff.set_path(file_path);
  ff.get_value(count_vert,count_facets, vertexes, facets);
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
    ASSERT_EQ(obj.vertexes[i], vertex[i]);
  }
  delete(obj.facets);
  delete(obj.vertexes);
}

TEST(test_open, 2) {
  s21::Model model;
  s21::Model::data_t obj;
  char file_path[30] = "obj/cub.obj";
  model.s21_count_v_f(file_path, &obj);
  model.s21_read(file_path, &obj);
  int indices_1[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
                     5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
                     0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
                     1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
  for (size_t i = 0; i < 72; i++) {
    ASSERT_EQ(obj.facets[i], indices_1[i]);
  }
  // delete(obj.facets);
  // delete(obj.vertexes);
}

// TEST(test_open, 2) {
//   s21::Model& model = s21::Model::getInstance();
//   s21::Model::data_t obj;
//   char file_path[30] = "obj/cub.obj";
//   model.s21_count_v_f(file_path, &obj);
//   model.s21_read(file_path, &obj);
//   int indices_1[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
//                      5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
//                      0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
//                      1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
//   for (size_t i = 0; i < 72; i++) {
//     ASSERT_EQ(obj.facets[i], indices_1[i]);
//   }
//   delete(obj.facets);
//   delete(obj.vertexes);
// }

// TEST(test_count_facets, 3) {
//   s21::Model model;
//   s21::Model::data_t obj ;
//   char file_path[30] = "obj/cub.obj";
//   model.s21_count_v_f(file_path, &obj);
//   ASSERT_EQ(obj.count_facets, 36);
//   delete(obj.facets);
//   delete(obj.vertexes);
//   // model.free(&obj);
// }

// TEST(test_count_vert, 4) {
//   s21::Model model;
//   s21::Model::data_t obj ;
//   char file_path[30] = "obj/cub.obj";
//   model.s21_count_v_f(file_path, &obj);
//   ASSERT_EQ(obj.count_vert, 8);
//   delete(obj.facets);
//   delete(obj.vertexes);
//   // model.free(&obj);
// }

// // TEST(move, 3) {
// //   s21::Move mv;
// //   s21::Model model;
// //   s21::Model::data_t obj ;
// //   char file_path[30] = "obj/cub.obj";
// //   model.s21_count_v_f(file_path, &obj);
// //   model.s21_read(file_path, &obj);
// //   mv.s21_move(&obj.vertexes, 0.9, obj.count_vert * 3, 'x');
// //   double vertex_1[] = {1.900000,  -1.000000, -1.000000, 1.900000,  -1.000000,
// //                        1.000000,  -0.100000, -1.000000, 1.000000,  -0.100000,
// //                        -1.000000, -1.000000, 1.900000,  1.000000,  -0.999999,
// //                        1.899999,  1.000000,  1.000001,  -0.100000, 1.000000,
// //                        1.000000,  -0.100000, 1.000000,  -1.000000};
// //   for (size_t i = 0; i < 24; i++) {
// //     // printf("%lf,", obj.vertexes[i]);
// //     ASSERT_NEAR(obj.vertexes[i], vertex_1[i], 1e-6);
// //   }
// //   model.free(&obj);
// // }

// // НЕ РАБОЧИЙ ТЕСТ
// // TEST(test_4, 4) {
// //   s21::Move mv;
// //   s21::Model model;
// //   s21::Model::data_t obj ;
// //   char file_path[30] = "obj/cub.obj";
// //   model.s21_count_v_f(file_path, &obj);
// //   model.s21_read(file_path, &obj);
// //   // s21_move(&obj.vertexes, 0.9, obj.count_vert * 3, 'x');
// //   mv.s21_move(&obj.vertexes, -1.4, obj.count_vert * 3, 'y');
// //   double vertex_1[] = {1.000000,  -2.400000, -1.000000, 1.000000,  -2.400000,
// //                        1.000000,  -1.000000, -2.400000, 1.000000,  -1.000000,
// //                        -2.400000, -1.000000, 1.000000,  -0.400000, -0.999999,
// //                        0.999999,  -0.400000, 1.000001,  -1.000000, -0.400000,
// //                        1.000000,  -1.000000, -0.400000, -1.000000};
// //   for (size_t i = 0; i < 24; i++) {
// //     // printf("%lf,", obj.vertexes[i]);
// //     ASSERT_NEAR(obj.vertexes[i], vertex_1[i], 1e-6);
// //   }
// //   model.free(&obj);
// //   // delete(obj.facets);
// //   // delete(obj.vertexes);
// // }

// // TEST(test_count_vert, 4) {
// //   s21::Model& model = s21::Model::getInstance();
// //   s21::Model::data_t obj ;
// //   char file_path[30] = "obj/cub.obj";
// //   model.s21_count_v_f(file_path, &obj);
// //   ASSERT_EQ(obj.count_vert, 8);
// //   // free(obj.count_vert);
// // }

// // Не рабочий тест
// // TEST(test_5, 5) {
// //   s21::Move mv;
// //   s21::Model model;
// //   s21::Model::data_t obj ;
// //   char file_path[30] = "obj/cub.obj";
// //   model.s21_count_v_f(file_path, &obj);
// //   model.s21_read(file_path, &obj);
// //   mv.s21_move(&obj.vertexes, 0.9, obj.count_vert * 3, 'x');
// //   double vertex_1[] = {1.900000,  -1.000000, -1.000000, 1.900000,  -1.000000,
// //                        1.000000,  -0.100000, -1.000000, 1.000000,  -0.100000,
// //                        -1.000000, -1.000000, 1.900000,  1.000000,  -0.999999,
// //                        1.899999,  1.000000,  1.000001,  -0.100000, 1.000000,
// //                        1.000000,  -0.100000, 1.000000,  -1.000000};
// //   for (size_t i = 0; i < 24; i++) {
// //     // printf("%lf,", obj.vertexes[i]);
// //     ASSERT_NEAR(obj.vertexes[i], vertex_1[i], 1e-6);
// //   }
// //   model.free(&obj);
// //   // free(obj.facets);
// //   // free(obj.vertexes);
// // }

// // TEST(test_6, 6) {
// //   s21::Scale sc;
// //   s21::Model model;
// //   s21::Model::data_t obj ;
// //   char file_path[30] = "obj/cub.obj";
// //   model.s21_count_v_f(file_path, &obj);
// //   model.s21_read(file_path, &obj);
// //   sc.s21_move(&obj.vertexes, 2.3, obj.count_vert * 3);
// //   double vertex_1[] = {2.300000,  -2.300000, -2.300000, 2.300000,  -2.300000,
// //                        2.300000,  -2.300000, -2.300000, 2.300000,  -2.300000,
// //                        -2.300000, -2.300000, 2.300000,  2.300000,  -2.299998,
// //                        2.299998,  2.300000,  2.300002,  -2.300000, 2.300000,
// //                        2.300000,  -2.300000, 2.300000,  -2.300000};
// //   for (size_t i = 0; i < 24; i++) {
// //     // printf("%lf,", obj.vertexes[i]);
// //     ASSERT_NEAR(obj.vertexes[i], vertex_1[i], 1e-6);
// //   }
// //   model.free(&obj);
// //   // delete(obj.facets);
// //   // delete(obj.vertexes);  
// // }

// // TEST(test_7, 7) {
// //   s21::Rotate rt;
// //   s21::Model model;
// //   s21::Model::data_t obj ;
// //   char file_path[30] = "obj/cub.obj";
// //   model.s21_count_v_f(file_path, &obj);
// //   model.s21_read(file_path, &obj);
// //   sc.s21_move(&obj.vertexes, 2.3, obj.count_vert * 3);
// //   double vertex_1[] = {2.300000,  -2.300000, -2.300000, 2.300000,  -2.300000,
// //                        2.300000,  -2.300000, -2.300000, 2.300000,  -2.300000,
// //                        -2.300000, -2.300000, 2.300000,  2.300000,  -2.299998,
// //                        2.299998,  2.300000,  2.300002,  -2.300000, 2.300000,
// //                        2.300000,  -2.300000, 2.300000,  -2.300000};
// //   for (size_t i = 0; i < 24; i++) {
// //     // printf("%lf,", obj.vertexes[i]);
// //     ASSERT_NEAR(obj.vertexes[i], vertex_1[i], 1e-6);
// //   }
// //   model.free(&obj);
// //   // delete(obj.facets);
// //   // delete(obj.vertexes);  
// // }

// TEST(MoveTest, MoveX) {
//   s21::Move move;
//   s21::Model::data_t obj;
//   obj.count_vert = 3;
//   obj.vertexes = new double[9] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
//   double expected[9] {2.0, 2.0, 3.0, 5.0, 5.0, 6.0, 8.0, 8.0, 9.0};

//   move.s21_move(&obj.vertexes, 1.0, obj.count_vert, 'x');

//   for (int i = 0; i < 9; ++i) {
//     EXPECT_DOUBLE_EQ(obj.vertexes[i], expected[i]);
//   }
//   delete[] obj.vertexes;
// }


// TEST(ScaleTest, Scale) {
//   s21::Scale scale;
//   s21::Model::data_t obj;
//   obj.count_vert = 3;
//   obj.vertexes = new double[9] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
//   double expected[9] {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0};

//   // Act
//   scale.s21_move(&obj.vertexes, 2.0, obj.count_vert);

//   // Assert
//   for (int i = 0; i < 9; ++i) {
//     EXPECT_DOUBLE_EQ(obj.vertexes[i], expected[i]);
//   }
//   delete[] obj.vertexes;
// }

TEST(MoveTest, MoveX) {
  s21::Move move;
  s21::Model::data_t obj;
  obj.count_vert = 3;
  obj.vertexes = new double[9] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  double expected[9] {2.0, 2.0, 3.0, 5.0, 5.0, 6.0, 8.0, 8.0, 9.0};

  move.s21_move(&obj.vertexes, 1.0, obj.count_vert, 'x');

  for (int i = 0; i < 9; ++i) {
    EXPECT_DOUBLE_EQ(obj.vertexes[i], expected[i]);
  }
  delete[] obj.vertexes;
}


TEST(ScaleTest, Scale) {
  s21::Scale scale;
  s21::Model::data_t obj;
  obj.count_vert = 3;
  obj.vertexes = new double[9] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  double expected[9] {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0};

  // Act
  scale.s21_move(&obj.vertexes, 2.0, obj.count_vert);

  // Assert
  for (int i = 0; i < 9; ++i) {
    EXPECT_DOUBLE_EQ(obj.vertexes[i], expected[i]);
  }
  delete[] obj.vertexes;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}