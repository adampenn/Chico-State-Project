#include "symbol.h"

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H


class Symbol_table {
  public:
    static Symbol_table* m_instance;
    Symbol_table();
    static Symbol_table* instance();
    Symbol* lookup(string name);
    void print(ostream &os);
    void insert(string name, Symbol* symbol);

  private:
    unordered_map<string, Symbol*> mymap;
    
};


#endif //SYMBOL_TABLE_H
