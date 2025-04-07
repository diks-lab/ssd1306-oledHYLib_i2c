#pragma once
#include <Arduino.h>

class baseObject
{
public:
  baseObject() {};
  ~baseObject() {};
  void init(int num) { _num = num; }
  void setEnable(bool enable) { _enabled = enable; }
  bool status(void) { return _enabled; }

protected:
  bool _enabled = false;
  int _num;
};

class ObjectA : public baseObject
{
public:
  void run(void);

private:
  void dispOled(int attr);
};

class ObjectB : public baseObject
{
public:
  void run(void);

private:
  void dispOled(int attr);
};

class ObjectC : public baseObject
{
public:
  void run(void);

private:
  void dispOled(int attr);
};

class ObjectD : public baseObject
{
public:
  void run(void);

private:
  void dispOled(int attr);
};

class ObjectE : public baseObject
{
public:
  void run(void);

private:
  void dispOled(int attr);
  void sub_drawberX(int lv, int y);
};
