#include "main.ih"
#include <thread>
#include <functional>

// int main(int argc, char const *argv[])
// {
//      Compiler compiler;

//      std::promise<CompilationJobs> promise1;
//      std::future<CompilationJobs> future1 = promise1.get_future();

//      std::thread compileThread(&Compiler::sendResult, &compiler, std::ref(promise1), "source1.cpp");

//      compiler.getResult(future1);

//      compileThread.join();
// }

#include "main.ih"
#include <thread>
#include <functional>
#include <vector>

int main(int argc, char const *argv[])
{
    Compiler compiler;
    
    // List of source files to compile
    //std::vector<std::string> sourceFiles = {"source1.cpp", "source2.cpp", "source3.cpp"};
    std::vector<std::string> sourceFiles = {"source1.cc", "source2.cc", "source3.cc"};
    // Vectors to store promises, futures, and threads
    std::vector<std::promise<CompilationJobs>> promises(sourceFiles.size());
    std::vector<std::future<CompilationJobs>> futures;
    std::vector<std::thread> compileThreads;
    
    futures.reserve(sourceFiles.size());
    compileThreads.reserve(sourceFiles.size());
    
    // Create futures and launch threads for each source file
    for (size_t i = 0; i < sourceFiles.size(); ++i)
    {
        // Get future from promise
        futures.push_back(promises[i].get_future());
        
        // Launch compilation thread
        compileThreads.emplace_back(&Compiler::sendResult, &compiler, 
                                   std::ref(promises[i]), sourceFiles[i]);
    }
    
    // Get results from all compilations
    for (auto& future : futures)
    {
        compiler.getResult(future);
    }
    
    // Wait for all threads to complete
    for (auto& thread : compileThreads)
    {
        thread.join();
    }
    
    return 0;
}