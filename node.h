#ifndef _node
#define _node

#include <new>
#include <iostream>


#include "table.h"
#include "messages.h"

#include "link.h"

class SimulationContext;

using namespace std;

class Node {
 private:
  unsigned number;
  SimulationContext    *context;
  double   bw;
  double   lat;

 public:
  Node(const unsigned n, SimulationContext *c, double b, double l);
  Node();
  Node(const Node &rhs);
  Node & operator=(const Node &rhs);
  virtual ~Node();

  virtual bool Matches(const Node &rhs) const;
  
  virtual void SetNumber(const unsigned n);
  virtual unsigned GetNumber() const;

  virtual void SetLatency(const double l);
  virtual double GetLatency() const;
  virtual void SetBW(const double b);
  virtual double GetBW() const;

  virtual void SendToNeighbors(RoutingMessage *m);

  //
  // Students will WRITE THESE
  //
  virtual void LinkUpdate(const Link *l);
  virtual void ProcessIncomingRoutingMessage(const RoutingMessage *m);
  virtual void GetRoute(const Node *destination, RoutingTableEntry *rte) const;
  virtual Table *GetRoutingTable() const;

  virtual ostream & Print(ostream &os) const;

};

inline ostream & operator<<(ostream &os, const Node &n) { return n.Print(os);}


#endif
