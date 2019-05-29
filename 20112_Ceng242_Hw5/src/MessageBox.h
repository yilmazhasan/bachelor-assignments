#ifndef __MESSAGE_BOX_H__
#define __MESSAGE_BOX_H__
#include <string>
#include <vector>

#include "Folder.h"
#include "Message.h"

using namespace std;

class MessageBox
{
public:
	/*----- DO NOT MODIFY/REMOVE  -----*/
	MessageBox(); // used for possible initializations
	~MessageBox(); // should remove all messages
	/**
	 * Returns the messages that belong to box named "messageBox"
	 */
	const vector<Message*>& getMessages(string messageBox) const;
	/**
	 * Put the given Message in a box named "messageBox"
	 * "messageBox" can be "inbox", "sentbox", "drafts", "trash" or
	 * any other user-defined string identifier. If a box with the 
	 * given name does not exist, it will be created 
	 */
	void putToBox(Message* message, string messageBox);
	/*----- DO NOT MODIFY/REMOVE  -----*/
	// TODO: add methods if required

	string name;
	vector<Folder*> box;
private:
	// TODO: add fields/methods if required
};

#endif
