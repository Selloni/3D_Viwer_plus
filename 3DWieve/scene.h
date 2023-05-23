#ifndef SCENE_H
#define SCENE_H

#include <QMessageBox>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QWidget>
#include <QtOpenGL>

#define GL_SILENCE_DEPRECATION

#include "../Controller/s21_controller.h"
#include "../Transform//s21_transform.h"
#include "../parsing/s21_viewer.h"

class Scene : public QOpenGLWidget {
 public:
  //  s21::Model model_;
  s21::Controller controller;

  void saveSetting();
  void loadSetting();
  void freeMem();
  void readFile(std::string path_file);

  Scene(QWidget *parent = nullptr);
  double *qVertexes = 0;      // хранятся в, цифры
  unsigned int *qFacets = 0;  // массив, в нем полигоны, 122331

  char *str;

  int lC = 0;  // color
  int lS = 1;  // style
  int lW = 1;  // width

  int vC = 0;
  int vS = 0;
  int vW = 1;

  QString file;
  double backRed;
  double backGreen;
  double backBlue;
  double backAlpha;

  double rotX = 0.6;
  double rotY = 0.6;
  double rotZ = 0.6;

  double moveX = 0.0;
  double moveY = 0.0;
  double moveZ = 0.0;

  int proj = 0;
  QString pathFile;

 private slots:
  QSettings *settings;
  QPoint mPos;

  void mousePressEvent(QMouseEvent *) override;  // click mouse
  void mouseMoveEvent(QMouseEvent *) override;   // move mouse

  void initializeGL() override;  // вызываеться после вызова конструктора
  void resizeGL(int w, int h) override;  //  когда изменяеться размер окна
  void paintGL() override;  // нужно перерасовть окно

  void lineColor(int l_c);
  void lineStyle(int l_s);
  void vertexColor(int w_c);
  void veretexStile(int v_s);
  void projection(int proj);
  void draw();

  float xRot_ = 0, yRot_ = 0, zRot_ = 0, zoomScale_ = 0, xTrans_ = 0,
        yTrans_ = 0, startY_ = 0, startX_ = 0;
  bool moving_ = false;
  bool dragging_ = false;
};

#endif  // SCENE_H
