#ifndef _INCLUDED_COMPILATIONMANAGER_H
#define _INCLUDED_COMPILATIONMANAGER_H

#include <condition_variable>
#include <mutex>
#include <queue>

#include "../CompilationJobs/compilationjobs.h" 


class CompilationManager
{
    std::queue<CompilationJobs> d_queue;
    std::condition_variable d_cond;
    std::mutex d_mutex;

    public:
        void producer(std::string const &sourceFile);
        void consumer();
};

#endif
