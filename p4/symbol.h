#include <unordered_map>
#include <iostream>
#include <string>
#include <list>
#include "gpl_assert.h"
#include "gpl_type.h"
#include "limits.h"

using std::unordered_map;
using std::string;
using std::cout;
using std::ostream;
using std::list;

#ifndef SYMBOL_H
#define SYMBOL_H

#define UNDEFINED_INDEX INT_MIN
#define UNDEFINED_SIZE INT_MIN

class Symbol {
  public:
    Symbol(string name, int size, Gpl_type type);
    Symbol(string name, int value);
    Symbol(string name, double value);
    Symbol(string name, string value);
    Gpl_type get_type();
    void set(int value, int index = UNDEFINED_INDEX);
    void set(double value, int index = UNDEFINED_INDEX);
    void set(string value, int index = UNDEFINED_INDEX);
    int get_int_value(int index = UNDEFINED_INDEX) const;
    double get_double_value(int index = UNDEFINED_INDEX) const;
    string get_string_value(int index = UNDEFINED_INDEX) const;
    void print(ostream &os);
  
  private:
    string m_name;
    void* m_value;
    int m_size;
    Gpl_type m_type;
};


#endif //SYMBOL_H
