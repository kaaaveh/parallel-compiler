#include "../CompilationManager/compilationmanager.ih"

void CompilationManager::producer(std::string const &sourceFile)
{
    while(true)
    {
        CompilationJobs compilationJob(sourceFile);
        // ... fill the compilation job
        scoped_lock lck {d_mutex};           // protect operations
        d_queue.push(compilationJob);       
        d_cond.notify_one();                // notify
                   // release d_mutex (at end of scope)
    }
}
