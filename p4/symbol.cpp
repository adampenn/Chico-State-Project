#include "symbol.h"

Symbol::Symbol(string name, Gpl_type type, string value){
  m_name = name;
  m_type = type;
  m_value = value;
}

Gpl_type Symbol::get_type(){
  return m_type;
}

int Symbol::get_int_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    return value;
  } else {
    return value[index];
  }
}

double Symbol::get_double_value(int index) const{
  
}

string Symbol::get_string_value(int index) const{
  
}

