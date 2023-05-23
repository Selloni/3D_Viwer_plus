#include "scene.h"
//#include <iostream>

Scene::Scene(QWidget* parent)
    : QOpenGLWidget(parent)

{
  settings = new QSettings(QDir::homePath() + "/save_config/settings.conf",
                           QSettings::IniFormat);
}

void Scene::freeMem() {
  if (controller.obj.facets && controller.obj.vertexes) {
    delete[] controller.obj.facets;
    delete[] controller.obj.vertexes;
    controller.obj.facets = 0;
    controller.obj.vertexes = 0;
    controller.obj.count_facets = 0;
    controller.obj.count_vert = 0;
    qcountFacets = 0;
    qcountVert = 0;
    qVertexes = 0;
    qFacets = 0;
  }
}

void Scene::readFile(std::string path_file) {
  freeMem();
  int err_flag = 1;
  err_flag = controller.SetPathFile(path_file);
  if (err_flag) {
    QMessageBox msgBox;
    msgBox.setText("The file was not considered");
    msgBox.exec();
  } else {
    controller.Open(path_file);
    qcountFacets = controller.obj.count_facets;
    qcountVert = controller.obj.count_vert;
    qVertexes = controller.obj.vertexes;
    qFacets = controller.obj.facets;
  }
}

void Scene::initializeGL() {
  glEnable(GL_DEPTH_TEST);  // буфер глубины
}

void Scene::resizeGL(int w, int h) {
  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);
}

void Scene::paintGL() {
  projection(proj);
  glClearColor(backRed / 255.0f, backGreen / 255.0f, backBlue / 255.0f,
               backAlpha / 255.0f);  //  colo bakcground
  if (controller.obj.count_facets > 3) {
//    glClear(GlCOLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -3);
    glRotatef(xRot_, 1, 0, 0);  // для движения мышью
    glRotatef(yRot_, 0, 1, 0);
    glRotatef(zRot_, 0, 0, 1);
    draw();
    //        update();
    //        saveSetting();
  }
}
void Scene::draw() {
  if (controller.obj.count_facets > 3) {
    glVertexPointer(3, GL_DOUBLE, 0, qVertexes);
    glEnableClientState(GL_VERTEX_ARRAY);
    veretexStile(vS);
    vertexColor(vC);
    if (vS != 0) {
      glPointSize(vW);  // size point
      glDrawArrays(GL_POINTS, 0, controller.obj.count_vert);
    }
    lineColor(lC);
    lineStyle(lS);
    glDrawElements(GL_LINES, (qcountFacets * 2), GL_UNSIGNED_INT, qFacets);
    glLineWidth(lW);  // size line
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void Scene::lineColor(int lC) {
  if (lC == 0) {
    glColor3f(1, 1, 1);
  } else if (lC == 1) {
    glColor3f(0, 0, 0.2);
  } else if (lC == 2) {
    glColor3f(0.5, 0, 0);
  } else if (lC == 3) {
    glColor3f(0.1, 1, 0.7);
  } else if (lC == 4) {
    glColor3f(0.1, 0, 1);
  }
}

void Scene::lineStyle(int lS) {
  if (lS == 1) {
    glDisable(GL_LINE_STIPPLE);
    glEnable(GL_LINE);
  } else if (lS == 0) {
    glLineStipple(1, 0x00ff);
    glEnable(GL_LINE_STIPPLE);  // пунктирная линия
  }
}

void Scene::vertexColor(int w_c) {
  if (w_c == 0) {
    glColor3f(1, 1, 1);
  } else if (w_c == 1) {
    glColor3f(0, 0, 0.2);
  } else if (w_c == 2) {
    glColor3f(0.5, 0, 0);
  } else if (w_c == 3) {
    glColor3f(0.1, 1, 0.7);
  } else if (w_c == 4) {
    glColor3f(0.1, 0, 1);
  }
}

void Scene::veretexStile(int vS) {
  if (vS == 1) {
    glEnable(GL_POINT_SMOOTH);  // круглые точки
  } else if (vS == 2) {
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT);  // точки
  }
}

void Scene::projection(int proj) {
  // Создаем проекцию
  glMatrixMode(GL_PROJECTION);  // ортоганальая поекция
  glLoadIdentity();             // загружаем матрицу
  if (proj) {
    // Establish clipping volume (left, right, bottom, top, near, far)
    glFrustum(-1, 1, -1, 1, 1, 99999);  //  перспективная проекция
  } else {
    glOrtho(-1, 1, -1, 1, -1, 99999);  // отоганальная
  }
}

void Scene::mousePressEvent(QMouseEvent* mouse) {
  switch (mouse->button()) {
    case Qt::LeftButton:
      moving_ = true;
      dragging_ = false;
      break;
    case Qt::MiddleButton:
      dragging_ = true;
      moving_ = false;
      break;
    default:
      moving_ = false;
      dragging_ = false;
      break;
  }
  startX_ = mouse->pos().x();
  startY_ = mouse->pos().y();
}

void Scene::mouseMoveEvent(QMouseEvent* mouse) {
  if (moving_) {
    yRot_ = yRot_ + (mouse->pos().x() - startX_);
    xRot_ = xRot_ + (mouse->pos().y() - startY_);
  }
  if (dragging_) {
    xTrans_ = xTrans_ + (mouse->pos().x() - startX_) / 4.f;
    yTrans_ = yTrans_ - (mouse->pos().y() - startY_) / 4.f;
  }
  startX_ = mouse->pos().x();
  startY_ = mouse->pos().y();
  update();
}

void Scene::saveSetting() {
  settings->setValue("lC", lC);
  settings->setValue("lS", lS);
  settings->setValue("lW", lW);
  settings->setValue("vC", vC);
  settings->setValue("vS", vS);
  settings->setValue("vW", vW);
  settings->setValue("lC", lC);
  settings->setValue("proj", proj);
  settings->setValue("backRed", backRed);
  settings->setValue("backGreen", backGreen);
  settings->setValue("backBlue", backBlue);
  settings->setValue("backAlpha", backAlpha);
}

void Scene::loadSetting() {
  lC = settings->value("lC", 0).toInt();
  lS = settings->value("lS", 0).toInt();
  lW = settings->value("lW", 0).toInt();
  vC = settings->value("vC", 0).toInt();
  vS = settings->value("vS", 0).toInt();
  vW = settings->value("vW", 0).toInt();
  proj = settings->value("proj", proj).toInt();
  backRed = settings->value("backRed", backRed).toFloat();
  backGreen = settings->value("backGreen", backGreen).toFloat();
  backBlue = settings->value("backBlue", backBlue).toFloat();
  backAlpha = settings->value("backAlpha", backAlpha).toFloat();
}
