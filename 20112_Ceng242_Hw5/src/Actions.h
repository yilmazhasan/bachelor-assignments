#ifndef _ACTIONS_H_
#define _ACTIONS_H_
#include<vector>
#include<string>
#include"Action.h"
#include "MessageBox.h"

class CopyAction :public Action
{
	public:
	string box;

	CopyAction(const string& box);
	virtual void execute(MessageBox* messageBox, Message* msg)const;
};

class MarkAsAction :public Action
{
	public:
	bool read;

	MarkAsAction(bool isread);
	virtual void execute(MessageBox* messageBox, Message* msg)const;
};
#endif
