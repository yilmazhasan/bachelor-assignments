#include "Actions.h"

CopyAction::CopyAction(const string& box)
{
	this->box = box;
}
int getInd(string name, vector<Folder*> vec)
{
	for(int i = 0; i < vec.size(); i++)
		if(vec[i]->name == name)
			return i;

	return -1;
}

void CopyAction::execute(MessageBox* messageBox, Message* msg)const
{
	Message *copy = new Message(msg->getID(), msg->getFrom(), msg->getTo(), msg->getCC(), msg->getBCC(), msg->getSubject(), msg->getBody(), msg->getDate());


	messageBox->putToBox(copy, box);
}

MarkAsAction::MarkAsAction(bool isread)
{
	this->read = isread;
}
void MarkAsAction::execute(MessageBox* messageBox, Message* msg)const
{
	msg->setIsRead(this->read);
}
