#include "symbol.h"

using std::unordered_map;
using std::string;

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H


class Symbol_table {
  public:
    static Symbol_table *Symbol_table::instance();
    Symbol *Symbol_table::lookup(string name);
    void Symbol_table::print(ostream &os);

  private:
    static Symbol_table* m_instance;
    unordered_map<string, Symbol*> mymap;
    
}


#endif //SYMBOL_TABLE_H
