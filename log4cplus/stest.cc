#include <Windows.h>
#include <iostream>
using namespace std;

#include <stdint.h>
#include <time.h>


#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include<log4cplus/fileappender.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

int main()
{

	log4cplus::initialize();
    SharedAppenderPtr _append(new FileAppender("Test.log"));

    _append->setName("filelogtest");
    std::string pattern = "%d{%m/%d/%y  %H:%M:%S}  - %m [%l]%n";
    std::auto_ptr<Layout> _layout(new PatternLayout(pattern));
    _append->setLayout( _layout );

    Logger _logger = Logger::getInstance("test");
    _logger.addAppender(_append);
    _logger.setLogLevel(ALL_LOG_LEVEL);
    
	LOG4CPLUS_DEBUG(_logger, "This is the  FIRST log message...");

    for (int i = 0;i < 10; ++i)
    {
         LOG4CPLUS_DEBUG(_logger, "my number is number my number is my number is my number is my number is my number is my number is");
    }
	system("pause");
    return 0;
}
