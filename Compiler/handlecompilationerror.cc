#include "../Compiler/compiler.ih"

void Compiler::handleCompilationError(std::string const &sourceFile)
{
    if (errorFile.is_open())
    {
        errorFile << "Error in file: " << sourceFile << '\n';
        errorFile.close();
    }
    else
    {
        std::cerr << "Unable to write error file!\n";
    }
}