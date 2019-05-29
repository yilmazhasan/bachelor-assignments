/* Filter.h
 *  Note: Do NOT modify this file!
 */
#ifndef __FILTER_H__
#define __FILTER_H__
#include <string>
#include "Message.h"
#include "Action.h"

using namespace std;

class Filter
{
public:
	/**
	 * Gets/sets the name of the Filter
	 */
	virtual string getName() const=0;
	virtual void setName(const string& name)=0;
	/**
	 * This pure virtual method determines whether a message
	 * passes this Filter or not
	 */
	virtual bool pass(const Message* message) const=0;
	/**
	 * Gets/sets the Action associated with this Filter
	 */
	virtual const Action* getAction() const=0;
	virtual void setAction(Action* action)=0;
	
};
#endif
