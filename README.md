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
