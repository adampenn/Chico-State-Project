#include "symbol.h"

Symbol::Symbol(string name, Gpl_type type, int value){
  m_name = name;
  m_type = type;
  m_value = (void *) new int(value);
}
Symbol::Symbol(string name, Gpl_type type, double value){
  m_name = name;
  m_type = type;
  m_value = (void *) new double(value);
}
Symbol::Symbol(string name, Gpl_type type, string value){
  m_name = name;
  m_type = type;
  m_value = (void *) new string(value);
}

Gpl_type Symbol::get_type(){
  return m_type;
}

void set(int value, int index) {
  assert(m_type == INT);
  m_value = (void *) value;
}

void set(double value) {
  assert(m_type == DOUBLE);
  m_value = (void *) value;
}

void set(string value) {
  assert(m_type == STRING);
  m_value = (void *) value;
}

int Symbol::get_int_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == INT);
    return (int *)value;
  } else {
    assert(m_type == INT_ARRAY);
    return (int *)value[index];
  }
}

double Symbol::get_double_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == DOUBLE);
    return (double *)value;
  } else {
    assert(m_type == DOUBLE_ARRAY)
    return (double *)value[index];
  }
}

string Symbol::get_string_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == STRING);
    return (string *)value;
  } else {
    assert(m_type == STRING_ARRAY);
    return (string *)value[index];
  }  
}
//make print function
