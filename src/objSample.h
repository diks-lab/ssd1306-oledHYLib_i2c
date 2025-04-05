#pragma once
#include <Arduino.h>

class ObjectA {
public:
  ObjectA() {};
  ~ObjectA() {};
  void init(int num);
  void run(void);
  void setEnable(bool enable) { _enabled = enable; }
  bool status(void){return _enabled;}

private:
  void dispOled(int attr);
  bool _enabled = false;
  int _num = 1;
};

class ObjectB {
public:
  ObjectB() {};
  ~ObjectB() {};
  void init(int num);
  void run(void);
  void setEnable(bool enable) { _enabled = enable; }
  bool status(void){return _enabled; }

private:
  void dispOled(int attr);
  bool _enabled = false;
  int _num = 1;
};

class ObjectC {
public:
  ObjectC() {};
  ~ObjectC() {};
  void init(int num);
  void run(void);
  void setEnable(bool enable) { _enabled = enable; }
  bool status(void){return _enabled; }

private:
  void dispOled(void);
  bool _enabled = false;
  int _num = 1;
};

class ObjectD {
public:
  ObjectD(){};
  ~ObjectD() {};
  void init(int num);
  void run(void);
  void setEnable(bool enable) { _enabled = enable; }
  bool status(void){return _enabled; }

private:
  void dispOled(void);
  bool _enabled = false;
  int _num = 1;
};

class ObjectE {
public:
  ObjectE() {};
  ~ObjectE() {};
  void init(int num);
  void run(void);
  void setEnable(bool enable) { _enabled = enable; }
  bool status(void){return _enabled; }

private:
  void dispOled(void);
  void sub_drawberX( int lv , int y );
  bool _enabled = false;
  int _num = 1;
};
