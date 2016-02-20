#include "symbol.h"

Symbol::Symbol(string name, int size, Gpl_type type){
  m_name = name;
  m_type = type;
  if (type == INT_ARRAY) {
    m_value = new int[size];
  } else if (type == DOUBLE_ARRAY) {
    m_value = new double[size];
  } else if (type == STRING_ARRAY) {
    m_value = new string[size];
  }
}
Symbol::Symbol(string name, int value){
  m_name = name;
  m_type = INT_ARRAY;
  m_value = (void *) new int(value);
}
Symbol::Symbol(string name, double value){
  m_name = name;
  m_type = DOUBLE;
  m_value = (void *) new double(value);
}
Symbol::Symbol(string name, string value){
  m_name = name;
  m_type = STRING;
  m_value = (void *) new string(value);
}

Gpl_type Symbol::get_type(){
  return m_type;
}

void Symbol::set(int value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == INT);
    m_value = (void *) &value;
  } else {
    assert(m_type == INT_ARRAY);
    ((int *)m_value)[index] = value;
  }
}

void Symbol::set(double value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == DOUBLE);
    m_value = (void *) &value;
  } else {
    assert(m_type == DOUBLE_ARRAY);
    ((double *)m_value)[index] = value;
  }
}

void Symbol::set(string value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == STRING);
    m_value = (void *) &value;
  } else {
    assert(m_type == STRING_ARRAY);
    ((string *)m_value)[index] = value;
  }
}

int Symbol::get_int_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == INT);
    return *((int *) m_value);
  } else {
    assert(m_type == INT_ARRAY);
    return ((int *)m_value)[index];
  }
}

double Symbol::get_double_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == DOUBLE);
    return *((double *)m_value);
  } else {
    assert(m_type == DOUBLE_ARRAY);
    return ((double *)m_value)[index];
  }
}

string Symbol::get_string_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == STRING);
    return *((string *)m_value);
  } else {
    assert(m_type == STRING_ARRAY);
    return ((string *)m_value)[index];
  }  
}

void Symbol::print(int index) {
  // if array go threw whole array;
  if (m_type == INT) {
    cout << "int " << m_name << " = " << *((int *) m_value);
  } else if (m_type == INT_ARRAY) {
    for (int i = 0; i < m_size; i++)
      cout << "int " << m_name << " = " << ((int *)m_value)[index];
  } else if (m_type == DOUBLE) {
    cout << "double " << m_name << " = " << *((double *) m_value);
  } else if (m_type == DOUBLE_ARRAY) {
    for (int i = 0; i < m_size; i++)
      cout << "double " << m_name << " = " << ((double *)m_value)[index];
  } else if (m_type == STRING) {
    cout << "string " << m_name << " = " << "\"" << *((string *) m_value) << "\"";
  } else if (m_type == STRING_ARRAY) {
    for (int i = 0; i < m_size; i++)
      cout << "string " << m_name << " = " << "\"" << ((string *)m_value)[i] << "\"";
  }
}
















