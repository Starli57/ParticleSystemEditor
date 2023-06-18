
#include "Logger.h"

namespace Logging
{
	Logger::Logger(const int maxMessagesCount) 
	{
		messages = new std::string[maxMessagesCount];
		messagesArraySize = maxMessagesCount;
	}

	Logger::~Logger()
	{
		delete[](messages);
	}

	void Logger::Log(const std::string& message)
	{
		messages[messageIndex] = message;
		messageIndex = (messageIndex + 1) % messagesArraySize;
	}

	int Logger::GetMaxMessagesCount()
	{
		return messagesArraySize;
	}
}