#include<iostream>
#include "Message.h"
#include "Folder.h"
#include<vector>
#include<string>


Folder::Folder()
{

}

Folder::Folder(string boxName)
{
	this->name = boxName;
}

Folder::Folder(string boxName, Message* message)
{
	this->name = boxName;
	this->box.push_back(message);
}

Folder::~Folder()
{
	for(int i = 0; i < box.size(); i++)
		delete box[i];
}


