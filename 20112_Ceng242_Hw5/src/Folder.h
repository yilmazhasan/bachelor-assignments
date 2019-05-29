#ifndef _FOLDER_H_
#define _FOLDER_H_
#include "Message.h"
#include<string>
#include<vector>

class Folder
{
	public:
	Folder();
	~Folder();
	Folder(string boxName);
	Folder(string boxName, Message* message);
	string name;
	vector<Message*> box;
};

#endif
