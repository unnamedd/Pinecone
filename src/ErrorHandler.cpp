
#include "../h/ErrorHandler.h"

#include <iostream>

using std::cout;
using std::endl;

ErrorHandler error;

string ErrorHandler::priorityToStr(ErrorPriority in)
{
	switch (in)
	{
	case SOURCE_ERROR:
		return "error";
		break;
		
	case SOURCE_WARNING:
		return "warning";
		break;
		
	case JSYK:
		return "jsyk";
		break;
		
	case INTERNAL_ERROR:
		return "internal error";
		break;
		
	case RUNTIME_ERROR:
		return "runtime error";
		break;
		
	default:
		return "unknown priority level";
		break;
	}
}

void ErrorHandler::log(string msg, ErrorPriority priority)
{
	if (priority==SOURCE_ERROR || priority==INTERNAL_ERROR)
		errorHasBeenLogged=true;
	
	//cout << data.file << ":" << ((data.line<0)?" ":std::to_string(data.line)+": ") << priorityToStr(priority) << ": " << msg << endl;
	cout << priorityToStr(priority) << ": " << msg << endl;
}

void ErrorHandler::log(string msg, ErrorPriority priority, Token token)
{
	if (priority==SOURCE_ERROR || priority==INTERNAL_ERROR)
		errorHasBeenLogged=true;
	
	cout << token->getFile() << ":" << token->getLine() << ":" << token->getCharPos() << ": " << priorityToStr(priority) << ": " << msg << endl;
}

void ErrorHandler::msg(string in)
{
	cout << "message: " << in << endl;
}
