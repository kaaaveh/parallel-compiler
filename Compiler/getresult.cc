#include "../Compiler/compiler.ih"

void Compiler::getResult(std::future<CompilationJobs> &fx)
{
    try
    {
        std::cout << "Waiting for compilation result..." << std::endl;
        CompilationJobs job = fx.get();
        std::cout << "Received result for: " << job.getSourceFile() << std::endl;
    }
    catch(...)
    {
        std::cout << "Exception caught while getting result" << std::endl;
        try
        {
            rethrow_exception(current_exception());
        }
        catch(std::exception const &e)
        {
            errorFile << e.what() << '\n';
            std::cout << "Exception details: " << e.what() << std::endl;
        }
    }
}