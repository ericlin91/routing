#include "node.h"
#include "context.h"
#include "error.h"


Node::Node(const unsigned n, SimulationContext *c, double b, double l) : 
    number(n), context(c), bw(b), lat(l) 
{}

Node::Node() 
{ throw GeneralException(); }

Node::Node(const Node &rhs) : 
  number(rhs.number), context(rhs.context), bw(rhs.bw), lat(rhs.lat) {}

Node & Node::operator=(const Node &rhs) 
{
  return *(new(this)Node(rhs));
}

void Node::SetNumber(const unsigned n) 
{ number=n;}

unsigned Node::GetNumber() const 
{ return number;}

void Node::SetLatency(const double l) 
{ lat=l;}

double Node::GetLatency() const 
{ return lat;}

void Node::SetBW(const double b) 
{ bw=b;}

double Node::GetBW() const 
{ return bw;}

Node::~Node()
{}

void Node::SendToNeighbors(const RoutingMessage *m)
{
  context->SendToNeighbors(this,m);
}

void Node::SendToNeighbor(const Node *n, const RoutingMessage *m)
{
  context->SendToNeighbor(this,n,m);
}

deque<Node*> *Node::GetNeighbors()
{
  return context->GetNeighbors(this);
}


bool Node::Matches(const Node &rhs) const
{
  return number==rhs.number;
}



void Node::LinkUpdate(const Link *l)
{
  cerr << *this << " got a link update: "<<*l<<endl;
  SendToNeighbors(new RoutingMessage);
  //WRITE
}


void Node::ProcessIncomingRoutingMessage(const RoutingMessage *m)
{
  cerr << *this << " got a routing messagee: "<<*m<<endl;
  // WRITE
}


Node *Node::GetNextHop(const Node *destination) const
{
  // WRITE
  return 0;
}

Table *Node::GetRoutingTable() const
{
  // WRITE
  return 0;
}


ostream & Node::Print(ostream &os) const
{
  os << "Node(number="<<number<<", lat="<<lat<<", bw="<<bw<<")";
  return os;
}
