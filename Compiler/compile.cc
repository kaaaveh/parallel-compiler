#include "../Compiler/compiler.ih"

bool Compiler::compile(std::string const &sourceFile, std::string const &outputFile)
{
    // Create object file instead of executable (add -c flag)
    std::string command = "g++ -std=c++2b -Wall -Werror -c " + sourceFile + " -o " + outputFile;
    d_result = std::system(command.c_str());

    if (d_result == 0)
    {
        std::cout << "Compilation Succeeded - Object file created: " << outputFile << std::endl;
        return true;
    }
    else 
    {
        std::cerr << "Compilation failed for: " << sourceFile << std::endl;
        handleCompilationError(sourceFile);
        return false;
    }
}