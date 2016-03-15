#include "symbol.h"

Symbol::Symbol(string name, int size, Gpl_type type){
  m_name = name;
  m_type = type;
  m_size = size;
  if (type == INT_ARRAY) {
    m_value = new int[size];
    for (int i=0; i < m_size; i++) {
      ((int*)m_value)[i] = 0;
    }
  } else if (type == DOUBLE_ARRAY) {
    m_value = new double[size];
    for (int i=0; i < m_size; i++) {
      ((double*)m_value)[i] = 0.0;
    }
  } else if (type == STRING_ARRAY) {
    m_value = new string[size];
    for (int i=0; i < m_size; i++) {
      ((string*)m_value)[i] = "";
    }
  }
}
Symbol::Symbol(string name, int value){
  m_name = name;
  m_type = INT;
  m_size = UNDEFINED_SIZE;
  m_value = (void *) new int(value);
}
Symbol::Symbol(string name, double value){
  m_name = name;
  m_type = DOUBLE;
  m_size = UNDEFINED_SIZE;
  m_value = (void *) new double(value);
}
Symbol::Symbol(string name, string value){
  m_name = name;
  m_type = STRING;
  m_size = UNDEFINED_SIZE;
  m_value = (void *) new string(value);
}

Gpl_type Symbol::get_type(){
  return m_type;
}

Gpl_type Symbol::get_base_type(){
  if (m_type == INT || m_type == INT_ARRAY) {
    return INT;
  } else if (m_type == DOUBLE || m_type == DOUBLE_ARRAY) {
    return DOUBLE;
  } else if (m_type == STRING || m_type == STRING_ARRAY) {
    return STRING;
  }
  assert(false && "No type declared");
  return INT;
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

void Symbol::print(ostream &os) {
  if (m_type == INT) {
    os << "int " << m_name << " = " << *((int *) m_value) << endl;
  } else if (m_type == INT_ARRAY) {
    for (int i = 0; i < m_size; i++)
      os << "int " << m_name << "[" << i << "] = " << ((int *)m_value)[i] << endl;
  } else if (m_type == DOUBLE) {
    os << "double " << m_name << " = " << *((double *) m_value) << endl;
  } else if (m_type == DOUBLE_ARRAY) {
    for (int i = 0; i < m_size; i++)
      os << "double " << m_name << "[" << i << "] = " << ((double *)m_value)[i] << endl;
  } else if (m_type == STRING) {
    os << "string " << m_name << " = " << "\"" << *((string *) m_value) << "\"" << endl;
  } else if (m_type == STRING_ARRAY) {
    for (int i = 0; i < m_size; i++)
      os << "string " << m_name << "[" << i << "] = " << "\"" << ((string *)m_value)[i] << "\"" << endl;
  }
}

