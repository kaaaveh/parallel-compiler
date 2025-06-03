#ifndef _INCLUDED_COMPILATIONJOBS_H
#define _INCLUDED_COMPILATIONJOBS_H

#include <iosfwd>
#include <string>

class CompilationJobs
{
    std::string const d_sourceFile;

    public:
        CompilationJobs(std::string const &sourceFile);
	    std::string const &getSourceFile() const;
	
};

#endif

/*
 * Implement the classes preparing the compilation jobs.
 * So this involves finding the sources to compile,
 * and notifying the compiling-clients about the next available
 * compilation job.
*/
