#include "../CompilationManager/compilationmanager.ih"

void CompilationManager::consumer()
{
    while(true)     // ML: Space after while keyword
    {
        unique_lock lck {d_mutex};                      //acquire d_mutex
        d_cond.wait(lck, [this] {return !d_queue.empty();}); // release d_mutex and wait
                                                        // re-acquire d_mutex upon wakeup
                                                        // don't wake up unless mqueue is non-empty
        auto compilationJob = d_queue.front();           // get the job
        d_queue.pop();
        lck.unlock();                                   // release d_mutex
        // ... process job ...
    }
}
