#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QTimer>
#include <QUrl>

#include "../GIFCreation/gifImage/qgifimage.h"
#include "../Transform//s21_transform.h"
#include "../parsing/s21_viewer.h"
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  float time;
  QVector<QImage> GIF;
  QTimer *record_time;
  QString qpath_file;
  bool is_recording;
  double tmp = 1;

 public slots:

  void on_pushButton_clicked();

  void on_line_color_activated(int index);

  void on_line_solid_clicked();

  void on_line_dashed_clicked();

  void on_line_width_valueChanged(int value);

  void on_vertex_color_activated(int index);

  void on_vertex_circle_clicked();

  void on_vertex_no_clicked();

  void on_vertex_square_clicked();

  void on_vertex_wigth_valueChanged(int value);

  void on_background_clicked();

  void on_rotateX_valueChanged(double arg1);

  void on_rotetaY_valueChanged(double arg1);

  void on_rotateZ_valueChanged(double arg1);

  void on_doubleSpinBox_6_valueChanged(double arg1);

  void on_doubleSpinBox_5_valueChanged(double arg1);

  void on_doubleSpinBox_4_valueChanged(double arg1);

  void on_actioninfo_triggered();

  void on_setting_scale_valueChanged(double arg1);

  void on_but_scale_clicked();

  void on_actionSol_triggered();

  void on_actionSave_settings_triggered();

  void on_actionLoad_settings_triggered();

  void on_actionbmp_triggered();

  void on_actionjpeg_triggered();

  void on_actionGif_2_triggered();

  void recording();

  void saveGIF();

  void on_action_triggered();

  void updateCountdown();

 private:
  Ui::MainWindow *ui;
  Scene scene;
  s21::MoveX move_x_ = s21::MoveX::GetInstance();
  s21::MoveY move_y_ = s21::MoveY::GetInstance();
  s21::MoveZ move_z_ = s21::MoveZ::GetInstance();
  s21::Scale scale_ = s21::Scale::GetInstance();
  s21::RotateX rotate_x_ = s21::RotateX::GetInstance();
  s21::RotateY rotate_y_ = s21::RotateY::GetInstance();
  s21::RotateZ rotate_z_ = s21::RotateZ::GetInstance();
  int countdown_ = 0;
};
#endif  // MAINWINDOW_H
