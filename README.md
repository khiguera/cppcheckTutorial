cppcheckTutorial
================

(TL;DR)

Cppcheck is a static code analysis tool for the C and C++ programming 
languages. It is a versatile tool that can check non-standard code. The 
creator and lead developer is Daniel Marjamäki. Unlike C/C++ compilers and 
many other analysis tools it does not detect syntax errors in the code. 
Cppcheck primarily detects the types of bugs that the compilers normally do
not detect. 
The goal is to detect only real errors in the code (i.e. have zero false positives).

Cppcheck is free software under the GNU General Public License.


HOW TO INSTALL
==================
Windows: 
	In order to install for Windows, it must be downloaded from their
	website which can be found at http://cppcheck.sourceforge.net/
	After downloading, run the .msi file and it should install automatically.

Linux:
	In order to install for Linux you can simply run the following command:

```
sudo apt-get install cppcheck
```

Mac:
	We were not able to figure out how to install onto Mac, We would recommend to either ssh
	into a server that can use it or to explore the wonders that is the internet and figure it
	out. If you do, you are more than welcome to contriubte that to this project.


Optional arguments
====================

--append=\<file\>

	This allows you to provide information about functions by providing an implementation for these.

-D<id>

	By default Cppcheck checks all configurations. Use -D to limit the checking. When -D is used the 
	checking is limited to the given configuration. Example: -DDEBUG=1 -D__cplusplus

--enable=<id>
	Enable additional checks. The available ids are:

	all

		Enable all checks
	style

		Check coding style
		
	information

		Enable information messages

	unusedFunction

		Check for unused functions
	
	missingInclude

		Check for missing includes

By default none of the additional checks are enabled. Several ids can be given if you separate them 
with commas, e.g. --enable=style,unusedFunction.

--error-exitcode=<n>

	If errors are found, integer <n> is returned instead of default 0. EXIT_FAILURE is returned 
	if arguments are not valid or if no input files are provided. Note that your operating 
	system can modify this value, e.g. 256 can become 0.

--errorlist

	Print a list of all possible error messages in XML format.

--exitcode-suppressions=<file>

	Used when certain messages should be displayed but should not cause a non-zero exitcode.

--file-list=<file>

	Specify the files to check in a text file. One filename per line.

-f, --force

	Force checking of files that have a lot of configurations. Error is printed if such a file is 
	found so there is no reason to use this by default.

-h, --help

	Print help text.

-I <dir>

	Give include path. Give several -I parameters to give several paths. First given path is checked 
	first. If paths are relative to source files, this is not needed.

-i <dir>

	Give path to ignore. Give several -i parameters to ignore several paths. Give directory name or 
	filename with path as parameter. Directory name is matched to all parts of the path.

--inline-suppr

	Enable inline suppressions. Use them by placing comments in the form: 
	// cppcheck-suppress memleak before the line to suppress.

-j <jobs>

	Start <jobs> threads to do the checking work.

-q, --quiet

	Only print something when there is an error.

--report-progress

	Report progress when checking a file.

--rule=<rule>

	Match regular expression to create your own checks. E.g. rule "/ 0" can be used to check 
	division by zero.

--rule-file=<file>

	Use given rule XML file. See https://sourceforge.net/projects/cppcheck/files/Articles/ for more 
	info about the syntax.

-s, --style

	Deprecated, use --enable=style

--suppress=<spec>

	Suppress a specific warning. The format of <spec> is: [error id]:[filename]:[line]. The 
	[filename] and [line] are optional. [error id] may be * to suppress all warnings (for a 
	specified file or files). [filename] may contain the wildcard characters * or ?.

--suppressions-list=<file>

	Suppress warnings listed in the file. Each suppression is in the format of <spec> above.

--template '<text>'

	Format the error messages. E.g. '{file}:{line},{severity},{id},{message}' or '{file}({line}):(
	{severity}) {message}'. Pre-defined templates: gcc, vs

-v, --verbose

	More detailed error reports

--version

	Print out version information

--xml

	Write results in XML to error stream

--xml-version=<version>

	Select the XML file version. Currently versions 1 and 2 are available. The default version is 1.
