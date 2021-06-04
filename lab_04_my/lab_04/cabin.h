#pragma once

#include <QObject>

#include "consts.h"
#include "controller.h"
#include "door.h"


class Cabin : public QObject {
  Q_OBJECT

public:
  explicit Cabin(QObject *parent = nullptr);

signals:
  void cabin_called();
  void cabin_crossing_floor(int floor, direction d);
  void cabin_reached_target(int floor);
  void cabin_stopped(int floor);

public slots:
  void cabin_move();
  void cabin_stopping();
  void cabin_call(int floor, direction dir);

private:
  enum state { MOVE, WAIT, STOP };
  state current_state;

  int current_floor;
  int target;
  bool new_target;
  direction current_direction;
  Door doors;
  QTimer crossing_floor_timer;
};
