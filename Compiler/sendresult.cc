#include "../Compiler/compiler.ih"

void Compiler::sendResult(std::promise<CompilationJobs> &px, std::string const &sourceFile)
{
    try
    {
        std::cout << "Starting compilation of: " << sourceFile << std::endl;
        
        // Create output filename (e.g., source1.cc -> source1.o)
        std::string outputFile = sourceFile;
        size_t dotPos = outputFile.find_last_of('.');
        if (dotPos != std::string::npos) {
            outputFile = outputFile.substr(0, dotPos) + ".o";
        } else {
            outputFile += ".o";
        }
        
        // Actually perform the compilation
        bool success = compile(sourceFile, outputFile);
        
        // Create the compilation job with the result
        CompilationJobs job(sourceFile);
        
        if (success) {
            std::cout << "Successfully compiled: " << sourceFile << " -> " << outputFile << std::endl;
        } else {
            std::cout << "Failed to compile: " << sourceFile << std::endl;
        }
        
        px.set_value(job);
    }
    catch(...)
    {
        std::cout << "Exception during compilation of: " << sourceFile << std::endl;
        px.set_exception(current_exception());

        try
        {
            rethrow_exception(current_exception());
        }
        catch(std::exception const &e)
        {
            errorFile << e.what() << '\n';
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}