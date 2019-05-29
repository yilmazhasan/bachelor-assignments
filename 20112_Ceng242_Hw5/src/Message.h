#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>
#include <iostream>

using namespace std;

class Message
{
public:
	/*----- DO NOT MODIFY/REMOVE  -----*/
	Message();
	Message(const string& _id, const string& _from, const string& _to, const string& _cc, const string& _bcc, 
			const string& _subject, const string& _body, const string& _date);
	const string& getID() const; // unique field, cannot be empty
	const string& getFrom() const; // non-empty string
	const string& getTo() const; // non-empty string
	const string& getCC() const; // can be empty
	const string& getBCC() const; // can be empty
	const string& getSubject() const; // can be empty
	const string& getBody() const; // can be empty
	const string& getDate() const; // non-empty string
	bool isRead() const; // not used for filtering
	void setIsRead(bool isread);
	/*----- DO NOT MODIFY/REMOVE  -----*/
	// TODO: add methods if required
private:
		string id;
		string from;
		string to;
		string cc;
		string bcc;
		string subject;
		string body;
		string date;
		bool read;

	// TODO: add fields/methods if required
};

#endif
