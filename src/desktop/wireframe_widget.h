#ifndef WIREFRAME_WIDGET_H
#define WIREFRAME_WIDGET_H

#include <QOpenGLBuffer>
#include <QOpenGLWidget>
#include <QtWidgets>
#include <vector>

namespace s21 {
class WireframeWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 private:
  std::vector<float> vbo_data_ = {};
  std::vector<int> ebo_data_ = {};

  float move_x_ = 0.0f;
  float move_y_ = 0.0f;
  float move_z_ = 0.0f;

  float rotate_x_ = 0.0f;
  float rotate_y_ = 0.0f;
  float rotate_z_ = 0.0f;

  float scale_ = 1.0f;

 public:
  WireframeWidget(QWidget *parent) : QOpenGLWidget(parent) {}

  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;

  void UpdateModel(std::vector<float> new_vbo,
                   std::vector<int> new_ebo) noexcept;

 public slots:
  void MoveX(int value);
  void MoveY(int value);
  void MoveZ(int value);

  void RotateX(int value);
  void RotateY(int value);
  void RotateZ(int value);

  void ScaleChanged(int value);
};
}  // namespace s21

#endif