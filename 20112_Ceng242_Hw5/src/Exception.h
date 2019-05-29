/* Exception.h
 *  Note: Do NOT modify this file!
 */
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include <string>

using namespace std;

class Exception
{
public:
	enum ErrorCode { BOX_NOT_EXISTS, ACTION_UNAVAILABLE };
	Exception(ErrorCode code, string msg) : errorCode(code), message(msg) {}
	void setCode(ErrorCode code) { errorCode = code; }
	void setMessage(string& msg) { message = msg; }
	int code() { return errorCode; }
	string what() { return message; }
private:
	ErrorCode errorCode;
	string message;
};
#endif
