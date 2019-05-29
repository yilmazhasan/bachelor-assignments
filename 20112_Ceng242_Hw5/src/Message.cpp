#include"Message.h"

Message::Message()
{

}

Message::Message(const string& _id, const string& _from, const string& _to, const string& _cc, const string& _bcc, 
			const string& _subject, const string& _body, const string& _date)
{
	this->id = _id;
	this->from = _from;
	this->to = _to;
	this->cc = _cc;
	this->bcc = _bcc;
	this->subject = _subject;
	this->body= _body;
	this->date = _date;
	this->read = false;
}

const string& Message::getID() const // unique field, cannot be empty
{
	return id;
}

const string& Message::getFrom() const // non-empty string
{
	return from;
}

const string& Message::getTo() const // non-empty string
{
	return to;
}

const string& Message::getCC() const // can be empty
{
	return cc;
}

const string& Message::getBCC() const // can be empty
{
	return bcc;
}

const string& Message::getSubject() const // can be empty
{
	return subject;
}

const string& Message::getBody() const // can be empty
{
	return body;
}

const string& Message::getDate() const // non-empty string
{
	return date;
}

bool Message::isRead() const // not used for filtering
{
	return this->read;
}

void Message::setIsRead(bool isread)
{
	this->read = isread;
}

