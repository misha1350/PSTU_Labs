#pragma once
class object
{
public:
  object(void);
  ~object(void);
  virtual void show()=0;
};

object::object() {}
object::~object() {}
