#include <iostream>
#include "Message.h"
#include "MessageBox.h"
#include "MessageClient.h"
#include "Filters.h"
#include "Actions.h"
#include "Exception.h"

using namespace std;

ostream& operator<<(ostream& os, const Message& message)
{
	// short output
	os << "Message::[ID:\"" << message.getID() << "\"][" << (message.isRead() ? "READ" : "UNREAD") << "]";
	// long output with headers
	/*
	os << "Message::[ID:\"" << message.getID() << "\"][From:\"" << message.getFrom() << "\"][To:\"" 
		<< message.getTo() << "\"][CC:\"" << message.getCC() << "\"][BCC:\"" << message.getBCC() 
		<< "\"][Subject:\"" << message.getSubject() << "\"][Body:\"" << message.getBody() << "\"][Date:\""
		<< message.getDate() << "\"][" << (message.isRead() ? "READ" : "UNREAD") << "]";
	*/
	// multiple line output
	/*
	os << "From: " << message.getFrom() << "\nTo: " << message.getTo() << "\nCC: " << message.getCC() << "\n"
		<< "BCC: " << message.getBCC() << "\nSubject: " << message.getSubject() << "\n" 
		<< "Body: " << message.getBody() << "\nIsRead: " << (message.isRead() ? "Yes" : "No") << endl;
	*/
	return os;
}


/**
 * Overloaded operator<< to print a Message vector to a stream
 */
ostream& operator<<(ostream& os, const vector<Message*>& items)
{
	vector<Message*>::const_iterator iter;
	for (iter=items.begin(); iter != items.end(); iter++) {
		Message* msg = *iter;
		os << *msg << endl;
	}
	return os;
}

/**
 * This methods prints a specific box of a MessageBox to a stream
 */
void printBox(ostream& os, const MessageBox& messageBox, const string& boxName)
{
	os << "---------------------------------------------\n";
	try {
		const vector<Message*>& box = messageBox.getMessages(boxName);
		os << "[" << boxName << "]: " << "\n----------------------\n" << box;
	} catch (Exception& e) {
		os << "Error [" << e.code() << "]: \"" << e.what() << "\"" << endl;
	}
	os << "---------------------------------------------\n";
}

/**
 * This function fills the argument vector with a number of Filter objects
 */
void getFilters(vector<Filter*>& filters)
{
	Filter* filter;
	Action* action;
	// Subject contains "Ceng140" (case-insensitive)
	filter = new ContainsFilter("Subject", "Ceng140", false);
	action = new CopyAction("ceng140");
	filter->setAction(action);
	filter->setName("ceng140");
	filters.push_back(filter);
	// From equals "erdal@ceng.metu.edu.tr" (case-sensitive)
	filter = new EqualsFilter("From", "erdal@ceng.metu.edu.tr");
	action = new CopyAction("erdal@ceng");
	filter->setAction(action);
	filter->setName("erdal@ceng");
	filters.push_back(filter);
	// CC not contains "ceng.metu.edu.tr" (case-sensitive)
	filter = new NegateFilter(new ContainsFilter("CC", "ceng.metu.edu.tr"));
	action = new CopyAction("notceng");
	filter->setAction(action);
	filter->setName("notceng");
	filters.push_back(filter);
	// Date after "10/10/2011"
	filter = new DateFilter("10/10/2011", DateFilter::GREATER_THAN);
	action = new CopyAction("after");
	filter->setAction(action);
	filter->setName("after");
	filters.push_back(filter);
	// Date before "8/9/2010"
	filter = new DateFilter("8/9/2010", DateFilter::LESS_THAN);
	action = new CopyAction("before");
	filter->setAction(action);
	filter->setName("before");
	filters.push_back(filter);
	// Body contains METU but not Hacettepe
	filter = (new CompositeFilter(CompositeFilter::ALL))->
		addFilter(new ContainsFilter("Body", "METU", false))->
		addFilter(new NegateFilter(new ContainsFilter("Body", "Hacettepe")));
	action = new MarkAsAction(true);
	filter->setAction(action);
	filter->setName("metu");
	filters.push_back(filter);
	// To, CC or BCC ends with "gmail.com"
	filter = (new CompositeFilter(CompositeFilter::ANY))->
		addFilter(new EndsWithFilter("To", "gmail.com"))->
		addFilter(new EndsWithFilter("CC", "gmail.com"))->
		addFilter(new EndsWithFilter("BCC", "gmail.com"));
	action = new CopyAction("gmail");
	filter->setAction(action);
	filter->setName("gmail");
	filters.push_back(filter);
	// To begins with either "erdal@" or "e144909", and 
	// From not contains "gmail.com" and Subject contains "(No subject)"
	filter = (new CompositeFilter(CompositeFilter::ALL))->
		addFilter((new CompositeFilter(CompositeFilter::ANY))->
					addFilter(new BeginsWithFilter("To", "erdal@"))->
					addFilter(new BeginsWithFilter("To", "e144909")))->
		addFilter((new CompositeFilter(CompositeFilter::NONE))->
					addFilter(new ContainsFilter("From", "gmail.com"))->
					addFilter(new NegateFilter(new EqualsFilter("Subject", "(No subject)"))));
	action = new CopyAction("complex");
	filter->setAction(action);
	filter->setName("complex");
	filters.push_back(filter);
	// Filter with a contradiction; it should not affect any messages
	filter = (new CompositeFilter(CompositeFilter::ALL))->
		addFilter(new EqualsFilter("From", "user"))->
		addFilter(new NegateFilter(new EqualsFilter("From", "user")));
	action = new CopyAction("nihil"); // box "nihil" will not be created
	filter->setAction(action);
	filter->setName("nihil");
	filters.push_back(filter);
	// Filter without an action; MessageClient should throw an Exception
	filter = new EqualsFilter("From", "user@example.com");
	filter->setName("no action");
	filters.push_back(filter);
}

/**
 * This function fills the argument vector with a number of Message objects 
 */
void getMessages(vector<Message*>& messages)
{
	// ID From To CC
	// BCC Subject Body Date
	messages.push_back(
			new Message("1", "erdal@ceng.metu.edu.tr", "ceng140", "ceng140@ceng.metu.edu.tr", 
				"", "Welcome to Ceng140", "Recitations start on February 27th. Please fill your busy hour until.", "20/02/2012")
	);
	messages.push_back(
			new Message("2", "erdal@ceng.metu.edu.tr", "ceng242.news.ceng.metu.edu.tr", "erdal@ceng.metu.edu.tr", 
				"erdal@metu.edu.tr", "ceng242 hw5", "Dear all; Hw5 is available on COW.", "14/05/2012")
	);
	messages.push_back(
			new Message("3", "erdal@ceng.metu.edu.tr", "ceng111.news.ceng.metu.edu.tr", "ceng111@ceng.metu.edu.tr", 
				"", "Re: Welcome", "", "11/12/2012")
	);
	messages.push_back(
			new Message("4", "carlos@gmail.com", "chuck@gmail.com", "", 
				"", "University Application", "Hi Chuck; You can apply to both METU and Hacettepe for grad a position!", "05/04/2009")
	);
	messages.push_back(
			new Message("5", "e144909@metu.edu.tr", "erdal@metu.edu.tr", "", 
				"", "(No subject)", "Nothing much to tell", "08/07/2008")
	);
	messages.push_back(
			new Message("6", "alice@crpyt.org", "bob@crypt.org", "", 
				"carol@crypt.org", "Very secret message", "Benjamin Randell Harris was a British infantryman who served in the British army during the Napoleonic Wars.", "27/03/2012")
	);
}

int main()
{
	// create an instance of MessageClient
	//  all interaction will be done via this object
	MessageClient client;
	// get test filters and register them to MessageClient object
	vector<Filter*> filters;
	getFilters(filters);
	vector<Filter*>::iterator iter;
	for (iter=filters.begin(); iter != filters.end(); iter++) {
		try {
			// Register the Filter to MessageClient
			Filter* filter = *iter;
			client.addFilter(filter);
		} catch (Exception& e) {
			cout << "Error [" << e.code() << "]: \"" << e.what() << "\"" << endl;
		}
	}
	// create test messages and pass them to MessageClient object
	vector<Message*> messages;
	getMessages(messages);
	vector<Message*>::iterator it;
	for (it=messages.begin(); it != messages.end(); it++) {
		// let MessageClient handle each message
		Message* message = *it;
		client.receive(message);
	}
	// get the MessageBox reference from MessageClient
	MessageBox& messageBox = client.getMessageBox();
	// print default boxes (these exist even if they do not contain any messages)
	printBox(cout, messageBox, "inbox");
	printBox(cout, messageBox, "sentbox");
	printBox(cout, messageBox, "drafts");
	printBox(cout, messageBox, "trash");
	// print user-created boxes
	printBox(cout, messageBox, "ceng140");
	printBox(cout, messageBox, "erdal@ceng");
	printBox(cout, messageBox, "notceng");
	printBox(cout, messageBox, "gmail");
	printBox(cout, messageBox, "after");
	printBox(cout, messageBox, "before");
	printBox(cout, messageBox, "complex");
	// message boxes "nihil" and "test" do not exist
	printBox(cout, messageBox, "nihil");
	printBox(cout, messageBox, "test");
	// 
	vector<Message*> filtered = client.search(new ContainsFilter("Body", "you", false));
	cout << "[filtered]:" << endl;
	cout << filtered;
	return 0;
}
