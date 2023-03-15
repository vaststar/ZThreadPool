#include "ThreadPoolUtil.h"
#include "LogExport.h"

#include <vector>
#include <string>
#include <functional>

#define TEST_LOG_DEBUG(message) LOG_DEBUG("TEST_LOG",message)
int main(int argc, char* argv[])
{
	MasterLogUtil::initConsoleLog();
    ThreadPoolUtil::initThreadPool(5);
    for(int i=0;i<500;++i)
    {
        ThreadPoolUtil::createThreadTask([i](){
            TEST_LOG_DEBUG( "excute res:" << i*i);
        });
    }
	return 0;
}