#include <unordered_map>
#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include "gpl_assert.h"
#include "gpl_type.h"
#include "limits.h"
#include "error.h"
#include "circle.h"
#include "rectangle.h"
#include "pixmap.h"
#include "textbox.h"
#include "triangle.h"
#include "animation_block.h"
#include <sstream>

using std::stringstream;
using std::unordered_map;
using std::string;
using std::cout;
using std::ostream;
using std::list;
using std::endl;
using std::to_string;

#ifndef SYMBOL_H
#define SYMBOL_H

#define UNDEFINED_INDEX INT_MIN
#define UNDEFINED_SIZE INT_MIN

class Symbol {
  public:
    Symbol(string name, Animation_block* animation_block);
    Symbol(string name, Gpl_type type, Game_object* game_object);
    Symbol(string name, int size, Gpl_type type);
    Symbol(string name, int value);
    Symbol(string name, double value);
    Symbol(string name, string value);
    Gpl_type get_type();
    Gpl_type get_base_type();
    void set(int value, int index = UNDEFINED_INDEX);
    void set(double value, int index = UNDEFINED_INDEX);
    void set(string value, int index = UNDEFINED_INDEX);
    int get_int_value(int index = UNDEFINED_INDEX) const;
    double get_double_value(int index = UNDEFINED_INDEX) const;
    string get_string_value(int index = UNDEFINED_INDEX) const;
    Game_object* get_game_object_value(int index = UNDEFINED_INDEX) const;
    Animation_block* get_animation_block_value() const;
    string get_name() const;
    void print(ostream &os);
    bool is_game_object();  
  private:
    string m_name;
    void* m_value;
    int m_size;
    Gpl_type m_type;
};


#endif //SYMBOL_H
