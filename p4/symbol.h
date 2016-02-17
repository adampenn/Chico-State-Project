#include <unordered_map>
#include <iostream>
#include <string>

#ifndef SYMBOL_H
#define SYMBOL_H

#define UNDEFINED_INDEX -1

class Symbol {
  public:
    Symbol(string name, Gpl_type type, string value);
    Gpl_type get_type();
    int get_int_value(int index = UNDEFINED_INDEX) const;
    double get_double_value(int index = UNDEFINED_INDEX) const;
    string get_string_value(int index = UNDEFINED_INDEX) const;
  
  private:
    string m_name, m_value; // should value be a pointer or somethign to deal with it being int double and string and arrays
    Gpl_type m_type;
    
}


#endif //SYMBOL_H
