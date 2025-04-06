#pragma once
#include <Arduino.h>

class ObjectA {
public:
  ObjectA() {};
  ~ObjectA() {};
  void init(int num);
  void run(void);
  void setEnable() { _enabled = true; }
  bool status(void){return _enabled;}

private:
  void dispOled(int attr);
  bool _enabled = false;
  int _num ;
};

class ObjectB {
public:
  ObjectB() {};
  ~ObjectB() {};
  void init(int num);
  void run(void);
  void setEnable() { _enabled = true; }
  bool status(void){return _enabled; }

private:
  void dispOled(int attr);
  bool _enabled = false;
  int _num ;
};

class ObjectC {
public:
  ObjectC() {};
  ~ObjectC() {};
  void init(int num);
  void run(void);
  void setEnable() { _enabled = true; }
  bool status(void){return _enabled; }

private:
  void dispOled(void);
  bool _enabled = false;
  int _num ;
};

class ObjectD {
public:
  ObjectD(){};
  ~ObjectD() {};
  void init(int num);
  void run(void);
  void setEnable() { _enabled = true; }
  bool status(void){return _enabled; }

private:
  void dispOled(void);
  bool _enabled = false;
  int _num ;
};

class ObjectE {
public:
  ObjectE() {};
  ~ObjectE() {};
  void init(int num);
  void run(void);
  void setEnable() { _enabled = true; }
  bool status(void){return _enabled; }

private:
  void dispOled(void);
  void sub_drawberX( int lv , int y );
  bool _enabled = false;
  int _num ;
};
