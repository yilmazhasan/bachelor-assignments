/* Action.h
 *  Note: Do NOT modify this file!
 */
#ifndef __ACTION_H__
#define __ACTION_H__
#include "Message.h"
#include "MessageBox.h"

using namespace std;

class Action
{
public:
	/**
	 * This pure virtual method takes a reference of MessageBox and Message. 
	 * MessageClient uses this method to execute the Action of a Filter
	 */
	virtual void execute(MessageBox* messageBox, Message* msg)const=0;
};
#endif
