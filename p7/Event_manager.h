#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "expression.h"


class Event_manager {
  public:
    static Event_manager* m_instance;
    Event_manager();
    static Event_manager* instance();
    void execute_handlers(Window::Keystroke keystroke);
  private:
};

#endif // EVENT_MANAGER_H
