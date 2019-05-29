#include"MessageClient.h"
#include"Exception.h"


MessageClient::MessageClient() // used for possible initializations
{
	messageBox = new MessageBox();
}

MessageClient::~MessageClient()
{
	delete messageBox;
}

void MessageClient::receive(Message* message)
{
	int control = 0;
	string inbox = "inbox";
	

	for(int i = 0; i < filters.size(); i++)
		if(filters[i]->pass(message))
			 filters[i]->getAction()->execute(messageBox, message);

	this->messageBox->putToBox(message, inbox);

}

void MessageClient::addFilter(const Filter* filter)
{
	if(filter != NULL)
	if(filter->getAction() == NULL)
		throw Exception(Exception::ACTION_UNAVAILABLE, ("No action is associated with this filter: '" + filter->getName() + "'"));
	else
		this->filters.push_back(filter);
}

vector<Message*> MessageClient::search(const Filter* filter)
{
	vector<Message*> vec;
	
	for(int i = 0; i < messageBox->box[0]->box.size(); i++)
		if(filter->pass(messageBox->box[0]->box[i]))
			vec.push_back(messageBox->box[0]->box[i]);

	return vec;
}

MessageBox& MessageClient::getMessageBox()
{
	return *(this->messageBox);
}

