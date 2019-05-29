#ifndef __MESSAGE_CLIENT_H__
#define __MESSAGE_CLIENT_H__
#include <vector>

#include "MessageBox.h"
#include "Filter.h"

using namespace std;

class MessageClient
{
public:
	~MessageClient();
	/*----- DO NOT MODIFY/REMOVE  -----*/
	MessageClient(); // used for possible initializations
	/**
	 * Receives a message from the user, applies all 
	 * registered filters and saves the message to inbox. 
	 */
	void receive(Message* message);
	/**
	 * Registers a Filter. 
	 */
	void addFilter(const Filter* filter);
	/**
	 * Performs a filter-based search on messages in "inbox" 
	 * and returns those which pass the given Filter
	 */
	vector<Message*> search(const Filter* filter);
	/**
	 * Returns an instance of MessageBox class. This means
	 * MessageClient holds an instance of MessageBox
	 */
	MessageBox& getMessageBox();
	/*----- DO NOT MODIFY/REMOVE  -----*/
	// TODO: add methods if required
	
	MessageBox* messageBox;
	vector<const Filter*> filters;
	
private:
	// TODO: add fields/methods if required
};

#endif
