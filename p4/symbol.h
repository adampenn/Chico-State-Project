#include <unordered_map>
#include <iostream>
#include <string>
#include "gpl_assert.h"

#ifndef SYMBOL_H
#define SYMBOL_H

#define UNDEFINED_INDEX INT_MIN

class Symbol {
  public:
    Symbol(string name, Gpl_type type, string value);
    Gpl_type get_type();
    int get_int_value(int index = UNDEFINED_INDEX) const;
    double get_double_value(int index = UNDEFINED_INDEX) const;
    string get_string_value(int index = UNDEFINED_INDEX) const;
  
  private:
    string m_name;
    void* m_value;
    int m_size;
    Gpl_type m_type;
    
}


#endif //SYMBOL_H
