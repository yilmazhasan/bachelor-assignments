#include"Filters.h"
#include"Message.h"

EqualsFilter::EqualsFilter(const string& field, const string& value, bool caseSensitive)
{
	this->field = field;
	this->value = value;
	this->caseSensitive = caseSensitive;
	this->action = NULL;
}
string EqualsFilter::getName() const
{
	return name;
}
void EqualsFilter::setName(const string& name)
{
	this->name = name;
}
bool checkCaseless(string a, string b)
{
	for(int i = 0; i < a.size(); i++)
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
	for(int i = 0; i < b.size(); i++)
		if(b[i] >= 'A' && b[i] <= 'Z')
			b[i] = b[i] - 'A' + 'a';
	
	return a == b;
}
string lowerCase(string a)
{
	for(int i = 0; i < a.size(); i++)
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
	
	return a;
}
bool EqualsFilter::pass(const Message* message) const
{

	if(this->caseSensitive) // if case is sensitive
	{
		if(field == "ID")
			return message->getID() == value;
		else if(field == "From")
			return message->getFrom() == value;
		else if(field == "To")
			return message->getTo() == value;
		else if(field == "CC")
			return message->getCC() == value;
		else if(field == "BCC")
			return message->getBCC() == value;
		else if(field == "Subject")
			return message->getSubject() == value;
		else if(field == "Body")
			return message->getBody() == value;
		else if(field == "Date")
			return message->getDate() == value;
	}
	else	//if case is nonsensitive, convert all to lower case and check with the checkCaseless func.
	{
		if(field == "ID")
			return checkCaseless(message->getID(), value);
		else if(field == "From")
			return checkCaseless(message->getFrom(), value);
		else if(field == "To")
			return checkCaseless(message->getTo(), value);
		else if(field == "CC")
			return checkCaseless(message->getCC(), value);
		else if(field == "BCC")
			return checkCaseless(message->getBCC(), value);
		else if(field== "Subject")
			return checkCaseless(message->getSubject(), value);
		else if(field == "Body")
			return checkCaseless(message->getBody(), value);
		else if(field == "Date")
			return checkCaseless(message->getDate(), value);

	}
}
const Action* EqualsFilter::getAction() const
{
	return action;
}
void EqualsFilter::setAction(Action* action)
{
	this->action = action;
}



ContainsFilter::ContainsFilter(const string& field, const string& value, bool caseSensitive)
{
	this->field = field;
	this->value = value;
	this->caseSensitive = caseSensitive;
	this->action = NULL;
}
string ContainsFilter::getName() const
{
	return this->name;
}
void ContainsFilter::setName(const string& name)
{
	this->name = name;
}
bool convertToBool(int a, string b)
{
	if ( a >= 0 && a < b.size())
		return true;
	else return false;
}
bool containsCaseless(string a, string b)
{
	int found = -1;

	for(int i = 0; i < a.size(); i++)
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
	for(int i = 0; i < b.size(); i++)
		if(b[i] >= 'A' && b[i] <= 'Z')
			b[i] = b[i] - 'A' + 'a';

		found = a.find(b);
		if(found == -1)
			return false;
		else return true;
}
bool ContainsFilter::pass(const Message* message) const
{
	int found = -1;
	if(this->caseSensitive)
	{
		if(field == "ID")
			return convertToBool((message->getID()).find(value), (message->getID()));
		else if(field == "From")
			return convertToBool((message->getFrom()).find(value), (message->getFrom()));
		else if(field == "To")
			return convertToBool((message->getTo()).find(value), (message->getTo()));
		else if(field == "CC")
			return convertToBool((message->getCC()).find(value), (message->getCC()));
		else if(field == "BCC")
			return convertToBool((message->getBCC()).find(value), (message->getBCC()));
		else if(field == "Subject")
			return convertToBool((message->getSubject()).find(value), (message->getSubject()));
		else if(field == "Body")
			return convertToBool((message->getBody()).find(value), (message->getBody()));
		else if(field == "Date")
			return convertToBool((message->getDate()).find(value), (message->getDate()));	
	}
	else
	{
		if(field == "ID")
			return containsCaseless(message->getID(), value);
		else if(field == "From")
			return containsCaseless(message->getFrom(), value);
		else if(field == "To")
			return containsCaseless(message->getTo(), value);
		else if(field == "CC")
			return containsCaseless(message->getCC(), value);
		else if(field == "BCC")
			return containsCaseless(message->getBCC(), value);
		else if(field == "Subject")
			return containsCaseless(message->getSubject(), value);
		else if(field == "Body")
			return containsCaseless(message->getBody(), value);
		else if(field == "Date")
			return containsCaseless(message->getDate(), value);
	
	}	
}
const Action* ContainsFilter::getAction() const
{
	return this->action;
}
void ContainsFilter::setAction(Action* action)
{
	this->action = action;
}







BeginsWithFilter::BeginsWithFilter(const string& field, const string& value, bool caseSensitive)
{
	this->field = field;
	this->value = value;
	this->caseSensitive = caseSensitive;
	this->action = NULL;

}
string BeginsWithFilter::getName() const
{
	return this->name;
}
void BeginsWithFilter::setName(const string& name)
{
	this->name= name;
}
bool beginsCaseless(string a, string b)
{
	for(int i = 0; i < a.size(); i++)
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
	for(int i = 0; i < b.size(); i++)
		if(b[i] >= 'A' && b[i] <= 'Z')
			b[i] = b[i] - 'A' + 'a';

	return a.find(b) == 0;
}
bool BeginsWithFilter::pass(const Message* message) const
{
	if(this->caseSensitive)
	{
		if(field == "ID")
			return (message->getID()).find(value) == 0;
		else if(field == "From")
			return (message->getFrom()).find(value) == 0;
		else if(field == "To")
			return (message->getTo()).find(value) == 0;
		else if(field == "CC")
			return (message->getCC()).find(value) == 0;
		else if(field == "BCC")
			return (message->getBCC()).find(value) == 0;
		else if(field == "Subject")
			return (message->getSubject()).find(value) == 0;
		else if(field == "Body")
			return (message->getBody()).find(value) == 0;
		else if(field == "Date")
			return (message->getDate()).find(value) == 0;	

	}
	else
	{
		if(field == "ID")
			return beginsCaseless(message->getID(), value);
		else if(field == "From")
			return beginsCaseless(message->getFrom(), value);
		else if(field == "To")
			return beginsCaseless(message->getTo(), value);
		else if(field == "CC")
			return beginsCaseless(message->getCC(), value);
		else if(field == "BCC")
			return beginsCaseless(message->getBCC(), value);
		else if(field == "Subject")
			return beginsCaseless(message->getSubject(), value);
		else if(field == "Body")
			return beginsCaseless(message->getBody(), value);
		else if(field == "Date")
			return beginsCaseless(message->getDate(), value);
	
	}	
}
const Action* BeginsWithFilter::getAction() const
{
	return this->action;
}
void BeginsWithFilter::setAction(Action* action)
{
	this->action = action;
}






EndsWithFilter::EndsWithFilter(const string& field, const string& value, bool caseSensitive)
{
	this->field = field;
	this->value = value;
	this->caseSensitive = caseSensitive;
	this->action = NULL;

}
string EndsWithFilter::getName() const
{
	return this->name;
}
void EndsWithFilter::setName(const string& name)
{
	this->name= name;
}
bool endsCaseless(string a, string b)
{
	for(int i = 0; i < a.size(); i++)
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
	for(int i = 0; i < b.size(); i++)
		if(b[i] >= 'A' && b[i] <= 'Z')
			b[i] = b[i] - 'A' + 'a';

	return a.find(b) == a.size()-b.size();
}
bool EndsWithFilter::pass(const Message* message) const
{
	if(this->caseSensitive)
	{
		if(field == "ID")
			return (message->getID()).find(value) == message->getID().size()-value.size();
		else if(field == "From")
			return (message->getFrom()).find(value) == message->getFrom().size()-value.size();
		else if(field == "To")
			return (message->getTo()).find(value) == message->getTo().size()-value.size();
		else if(field == "CC")
			return (message->getCC()).find(value) == message->getCC().size()-value.size();
		else if(field == "BCC")
			return (message->getBCC()).find(value) == message->getBCC().size()-value.size();
		else if(field == "Subject")
			return (message->getSubject()).find(value) == message->getSubject().size()-value.size();
		else if(field == "Body")
			return (message->getBody()).find(value) == message->getBody().size()-value.size();
		else if(field == "Date")
			return (message->getDate()).find(value) == message->getDate().size()-value.size();

	}
	else
	{
		if(field == "ID")
			return endsCaseless(message->getID(), value);
		else if(field == "From")
			return endsCaseless(message->getFrom(), value);
		else if(field == "To")
			return endsCaseless(message->getTo(), value);
		else if(field == "CC")
			return endsCaseless(message->getCC(), value);
		else if(field == "BCC")
			return endsCaseless(message->getBCC(), value);
		else if(field == "Subject")
			return endsCaseless(message->getSubject(), value);
		else if(field == "Body")
			return endsCaseless(message->getBody(), value);
		else if(field == "Date")
			return endsCaseless(message->getDate(), value);
	
	}	
}
const Action* EndsWithFilter::getAction() const
{
	return this->action;
}
void EndsWithFilter::setAction(Action* action)
{
	this->action = action;
}

DateFilter::DateFilter(const string& date, Operator op)
{
	this->date = date;
	this->op = op;
	this->action = NULL;
}
string DateFilter::getName() const
{
	return this->name;
}
void DateFilter::setName(const string& name)
{
	this->name = name;
}
int checkDate(string a, string b)
{
	string a1,a2,a3,b1,b2,b3;
	int i;

	for(i = 0; i < a.size(); i++)
	if(a[i] == '/')
		break;
	else a1.push_back(a[i]);

	for(i = i+1; i < a.size(); i++)
	if(a[i]== '/')
		break;
	else a2.push_back(a[i]);

	for(i = i+1; i < a.size(); i++)
	a3.push_back(a[i]);

	for(i = 0; i < b.size(); i++)
	if(b[i] == '/')
		break;
	else b1.push_back(b[i]);

	for(i = i+1; i < b.size(); i++)
	if(b[i] == '/')
		break;
	else b2.push_back(b[i]);

	for(i = i+1; i < b.size(); i++)
		b3.push_back(b[i]);

	string temp1, temp2;
	
	for(i = 0; i < a3.size(); i++)
		temp1.push_back(a3[i]);
	for(i = 0; i < b3.size(); i++)
		temp2.push_back(b3[i]);
	if(a2.size() == 1)
	{
		temp1.push_back('0');
		temp1.push_back(a2[0]);
	}
	else 
		{
			temp1.push_back(a2[0]);
			temp1.push_back(a2[1]);
		}
	if(a1.size() == 1)
	{
		temp1.push_back('0');
		temp1.push_back(a1[0]);
	}
	else 
		{
			temp1.push_back(a1[0]);
			temp1.push_back(a1[1]);
		}
	if(b2.size() == 1)
	{
		temp2.push_back('0');
		temp2.push_back(b2[0]);
	}
	else 
		{
			temp2.push_back(b2[0]);
			temp2.push_back(b2[1]);
		}
	if(b1.size() == 1)
	{
		temp2.push_back('0');
		temp2.push_back(b1[0]);
	}
	else 
		{
			temp2.push_back(b1[0]);
			temp2.push_back(b1[1]);
		}

		if(temp1 < temp2)
			return -1;
		else if(temp1 > temp2)
			return 1;
		else if(temp1 == temp2)
			return 0;

}

bool DateFilter::pass(const Message* message) const
{
	int control = checkDate(message->getDate(), this->date);

	if(control == -1 && this->op == LESS_THAN)
		return true;
	else if(control == 1 && this->op == GREATER_THAN)
		return true;
	else if(control == 0 && this->op == EQUAL)
		return true;
	else return false;
}
const Action* DateFilter::getAction() const
{
	return this->action;
}
void DateFilter::setAction(Action* action)
{
	this->action = action;
}


CompositeFilter::CompositeFilter(Composition comp)
{
	this->comp = comp;	
	this->action = NULL;
}
CompositeFilter* CompositeFilter::addFilter(const Filter* filter)
{
	this->filters.push_back(filter);
	return this;
}

string CompositeFilter::getName() const
{
	return this->name;	
}
void CompositeFilter::setName(const string& name)
{
	this->name = name;
}
bool CompositeFilter::pass(const Message* message) const
{
	int passed = 0;
	for(int i = 0; i < this->filters.size(); i++)
	{
		if(filters[i]->pass(message))
			passed++;
	}
	if(comp == ALL && passed == filters.size())
		return true;
	else if(comp == ANY && passed <= filters.size() && passed > 0)
		return true;
	else if(comp == NONE && passed == 0)
		return true;

	return false;
}
const Action* CompositeFilter::getAction() const
{
	return this->action;
}
void CompositeFilter::setAction(Action* action)
{
	this->action = action;
}


NegateFilter::NegateFilter(Filter* filter)
{
	this->action = NULL;
	this->filter = filter;
}
string NegateFilter::getName() const
{
	return this->name;
}
void NegateFilter::setName(const string& name)
{
	this->name = name;
}
bool NegateFilter::pass(const Message* message) const
{
	return !(this->filter->pass(message));
}
const Action* NegateFilter::getAction() const
{
	return this->action;
}
void NegateFilter::setAction(Action* action)
{
	this->action = action;
}



