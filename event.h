#ifndef _event
#define _event

#include <iostream>
#include <queue>

#include "messages.h"
#include "topology.h"

enum EventType { ADD_NODE, DELETE_NODE, ADD_LINK, DELETE_LINK,  
       CHANGE_NODE, CHANGE_LINK, WRITE_TOPOLOGY, DRAW_TOPOLOGY, 
       WRITE_TREE,DRAW_TREE, ROUTING_MESSAGE_ARRIVAL}; 

class Event {
 private:
  double timestamp;
  EventType etype;
  void  *handler;
  void  *data;

 public:
  Event(double t, EventType e, void *handler, void *d);
  // default copy construct and operator= is OK
  virtual ~Event();

  double GetTimeStamp();

  void Dispatch();
  void Disassociate();

  bool IsLater(const Event *rhs) const;

  ostream & Print(ostream &os) const;

};

inline ostream & operator<<(ostream &os, const Event &e) { return e.Print(os);}


struct CompareEvents : public binary_function<Event *,Event *, bool> {
  inline bool operator ()(const Event *lhs, const Event *rhs) {
    return lhs->IsLater(rhs);
  }
};



#endif
