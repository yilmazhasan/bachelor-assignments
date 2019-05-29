#ifndef _FILTERS_H_
#define _FILTERS_H_

#include "Message.h"
#include "Actions.h"
#include "Filter.h"

class EqualsFilter :public Filter
{
	public:
	EqualsFilter(const string& field, const string& value, bool caseSensitive=true);
	virtual string getName() const;
	virtual void setName(const string& name);
	virtual bool pass(const Message* message) const;
	virtual const Action* getAction() const;
	virtual void setAction(Action* action);

	string field;
	string value;
	bool caseSensitive;
	string name;
	Action* action;

};


class ContainsFilter : public Filter
{
	public:
	ContainsFilter(const string& field, const string& value, bool caseSensitive=true);
	virtual string getName() const;
	virtual void setName(const string& name);
	virtual bool pass(const Message* message) const;
	virtual const Action* getAction() const;
	virtual void setAction(Action* action);

	string field;
	string value;
	bool caseSensitive;
	string name;
	Action* action;

};

class BeginsWithFilter : public Filter
{
	public:
	BeginsWithFilter(const string& field, const string& value, bool caseSensitive=true);
	virtual string getName() const;
	virtual void setName(const string& name);
	virtual bool pass(const Message* message) const;
	virtual const Action* getAction() const;
	virtual void setAction(Action* action);

	string field;
	string value;
	bool caseSensitive;
	string name;
	Action* action;

};
class EndsWithFilter : public Filter
{
	public:
	EndsWithFilter(const string& field, const string& value, bool caseSensitive=true);
	virtual string getName() const;
	virtual void setName(const string& name);
	virtual bool pass(const Message* message) const;
	virtual const Action* getAction() const;
	virtual void setAction(Action* action);

	string field;
	string value;
	bool caseSensitive;
	string name;
	Action* action;

};


class DateFilter : public Filter
{
	public:
	enum Operator { EQUAL, LESS_THAN, GREATER_THAN };
	DateFilter(const string& date, Operator op);
	virtual string getName() const;
	virtual void setName(const string& name);
	virtual bool pass(const Message* message) const;
	virtual const Action* getAction() const;
	virtual void setAction(Action* action);


	string date;
	Operator op;
	string name;
	Action* action;
};



class CompositeFilter : public Filter
{
	public:
	enum Composition { ANY, ALL, NONE };
	CompositeFilter(Composition comp);
	CompositeFilter* addFilter(const Filter* filter);
	virtual string getName() const;
	virtual void setName(const string& name);
	virtual bool pass(const Message* message) const;
	virtual const Action* getAction() const;
	virtual void setAction(Action* action);

	Composition comp;
	vector<const Filter*> filters;
	string name;
	Action* action;

};

class NegateFilter : public Filter
{
	public:
	NegateFilter(Filter* filter);
	virtual string getName() const;
	virtual void setName(const string& name);
	virtual bool pass(const Message* message) const;
	virtual const Action* getAction() const;
	virtual void setAction(Action* action);

	string name;
	Action* action;
	Filter* filter;
};


#endif
