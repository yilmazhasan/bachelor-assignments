#include"MessageBox.h"
#include"Exception.h"

MessageBox::MessageBox()
{
	Folder* temp1 = new Folder("inbox");
	Folder* temp2 = new Folder("sentbox");
	Folder* temp3 = new Folder("drafts");
	Folder* temp4 = new Folder("trash");

	this->box.push_back(temp1);
	this->box.push_back(temp2);
	this->box.push_back(temp3);
	this->box.push_back(temp4);
}

MessageBox::~MessageBox()
{
	for(int i = 0; i < box.size(); i++)
		delete box[i];
}

int getIndex(string name, vector<Folder*> vec)
{
	for(int i = 0; i < vec.size(); i++)
		if(vec[i]->name == name)
			return i;

	return -1;
}

const vector<Message*>& MessageBox::getMessages(string messageBox) const
{
	int index = getIndex(messageBox, this->box);
	
	if(index == -1)
		throw *(new Exception(Exception::BOX_NOT_EXISTS,"MessageBox does not exist: '" + messageBox + "'"));
	else return this->box[index]->box;
}

void MessageBox::putToBox(Message* message, string messageBox)
{
	int index = getIndex(messageBox, this->box);
	if(index == -1)
	{
		Folder* temp = new Folder(messageBox);
		temp->box.push_back(message);
		this->box.push_back(temp);
	}
	else
	{
		this->box[index]->box.push_back(message);
	}
}


