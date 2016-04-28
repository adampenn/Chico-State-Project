#ifndef STATEMENT_H
#define STATEMENT_H

class Statement {
  public:
    Statement();
    virtual void execute() = 0;
};


#endif // STATEMENT_H
