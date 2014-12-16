cppcheckTutorial
================

As a heads up, if you are here trying to figure out how to use this tool for Windows, we can not be sure that everything discussed will work.
This tutorial was written mainly for Linux users as that is what we are using.


Quick Info
==========

<a href="http://cppcheck.sourceforge.net/" target="_blank">Cppcheck</a> is a static code analysis tool for the C/C++ programming languages. It is a versatile tool that can check non-standard code. 
The creator and lead developer is Daniel Marjamäki. Unlike C/C++ compilers and many other analysis tools it does not detect syntax errors in the code. 
Cppcheck primarily detects the types of bugs that the compilers normally do not detect. 
The goal is to detect only real errors in the code. 

Cppcheck is free software under the <a href=" http://www.gnu.org/copyleft/gpl.html" target="_blank">GPL</a>.


HOW TO INSTALL
==================

A download can be found <a href="http://sourceforge.net/projects/cppcheck/" target="_blank">here</a>.


Optional arguments
==================

Optional arguments are flags you can send to cppcheck to force it to check for certain things such as:

--enable=\<id\>
	Enable additional checks. The available ids are:

	all

		Enable all checks

	style

		Check coding style
		
	information

		Enable information messages

	unusedFunction

		Check for unused functions. 
		(This is pretty useful to clean up the source code.
		These funcitons may cause little gremlins later when trying to debug. 
		From experience, I have tried to fix bugs but tried fixing it by making changes to a function that is no longer been used.
		Three hours later, it was finally pointed out to me what I was doing...).
	
	missingInclude

		Check for missing include statements.

By default none of the additional checks are enabled.


**Note: _You can find all the optional arguments [here](http://linux.die.net/man/1/cppcheck)._**


How To Use cppcheck
===================

Alright, enough introductions lets get to what you are really interested in; how do you actually use this debugger?

<a name="outofbounds"></a>
In the code below, the user initializes a char array of size 10 and then assigns 0 to slot #10.
This seems ok at first glance, however the user forgot that by declaring an array of size 10, the array indicies go from 0 to 9.
What this means is that in the code line `a[10] = 0;` the `[10]` would go out of bounds.

```
int main()
{
	char a[10];
	a[10] = 0;

	return 0;
}
```

By running the command: `cppcheck badcode.cpp` the user is given the following:

```
$ cppcheck badcode.cpp
Checking badcode.cpp...
[badcode.cpp:10]: (error) Array 'a[10]' accessed at index 10, which is out of bounds.
```

Simply what this error states is that there is an assignment accessed at an out of bounds index.
This is just one method of using cppcheck to check your code for errors the compiler will not check at compile time.

Given the specific flags such as the `--enable=<id>` flag, you can test your code for a larger variety of errors.

Users should also configure cppcheck before diving into the program so that the checker will check the things the user wants it to check. 

Given the configuration and usage syntax of:
```
cppcheck [--append=<file>] [-D<id>] [--enable=<id>] [--error-exitcode=<n>] [--errorlist]
[--exitcode-suppressions=<file>] [--file-list=<file>] [--force] [--help] [-I<dir>] [-i<dir>] [--inline-suppr]
[-j<jobs>] [--quiet] [--report-progress] [--rule=<rule>] [--rule-file=<file>] [--style] [--suppress=<spec>]
[--suppressions-list=<file>] [--template '<text>'] [--verbose] [--version] [--xml] [--xml-version=<version>]]
[file or path] ...
```
the end user can customize the way the program functions in a number of ways such as error suppression or batch processing a directory of files.


##Using cppcheck With Other Programs

cppcheck can be configured to work with a number of development tools and is included in tools such as:
* <a href="http://www.codeblocks.org/downloads" target="_blank">Code::Blocks</a>
* <a href="http://codedx.com/" target="_blank">CodeDX</a>
* <a href="http://codelite.org/support.php" target="_blank">CodeLite</a>
* <a href="http://www.cppdepend.com/" target="_blank">CppDepend 5</a>

and can be installed as a package in tools such as:
* Eclipse (<a href="http://cppcheclipse.googlecode.com/" target="_blank">Cppcheclipse</a>)
* gedit (<a href="http://github.com/odamite/gedit-cppcheck" target="_blank">plugin</a>)
* Hudsons (<a href="http://wiki.hudson-ci.org/display/HUDSON/Cppcheck+Plugin" target="_blank">plugin</a>)
* Jenkins (<a href="http://wiki.jenkins-ci.org/display/JENKINS/Cppcheck+Plugin" target="_blank">plugin</a>)
* Visual Studios (<a href="https://github.com/VioletGiraffe/cppcheck-vs-addin/releases/latest" target="_blank">plugin</a>)
* Vim (<a href="http://www.vim.org/scripts/script.php?script_id=3017" target="_blank">plugin</a>)

the above are not the only programs with cppcheck integration but only a small portion.


What cppcheck can and can't do
=============================
##Capabilites of cppcheck

* out of bounds error check as seen [above](#outofbounds)
* class code checks
* code exception checking
* [memory leak checking](#memoryhole) to a certain extent
* obselete function usage warning
* invalid usage of STL
* usage of [uninitialized variables](#randomvariable) and [unused functions](#uselessfunction)




cppcheck Examples
=================
<a name="randomvariable"></a>
##Useless/Unused Variable Checking
```
int foo(int x)
{
	int i;
	if(x > 0 )
	{
		std::cout << "X is greater than 0." << std::endl;
		i = 1;
	}
}
```

cppcheck returns:
```
$ cppcheck --enable=style unusedvar.cpp
Checking unusedvar.cpp...
[unusedvar.cpp:9]: (style) The scope of the variable 'i' can be reduced.
[unusedvar.cpp:13]: (style) Variable 'i' is assigned a value that is never used.
```
####Why?
In this example, we see some stylistic problems with this code. 
While it may not cause any problems in the program, it is good practice to not have unnecessary code.
Although, cppcheck does not normally display these style isses.
In order to display the style issues, we run the command `--enable=style`.
At the same time, enabling style will also enable warning, performance, and portability issues.

<a name="uselessfunction"></a>
##Useless/Unused Function Checking
```
void greaterThanZero(int x)
{
	int i;
	if(x > 0 )
	{
		std::cout << "X is greater than 0." << std::endl;
		i = 1;
	}
}

int foo(int x, int y)
{
	return x + y;
}

int main()
{
	int a = 1, b = 2;
	foo(,b);

	return 0;
}
```

cppcheck returns:
```
$ cppcheck --enable=all useless.cpp
Checking useless.cpp...
[useless.cpp:9]: (style) The scope of the variable 'i' can be reduced.
[useless.cpp:13]: (style) Variable 'i' is assigned a value that is never used.
[useless.cpp:24]: (style) Variable 'a' is assigned a value that is never used.
Checking usage of global functions..
[useless.cpp:7]: (style) The function 'greaterThanZero' is never used.
```
####Why?
Because you wrote a function when it wasn't even needed. Sheesh what a waste of time.
Ok, fine here we added the main function.
We still get the same as errors for not using variables i, but now we also get errors for an unused function `greaterThanZero`.
_l2Code_

<a name="memoryhole"></a>
##Memory Leaks
```
int main()
{
	int *a;
	a = new int[10];
}
```

cppcheck returns:
```
$ cppcheck memleak.cpp
Checking memleak.cpp...
[memleak.cpp:11]: (error) Memory leak: a
```
####Sheesh a leak in this code... why??
Since the code allocated memory of 10 for a, there should have been followup code at the end calling `delete []a;`.
However since this was not done, a memory leak occurs where dynamically allocated memory was never freed.
Ideally the code should look like the following:
```
int main()
{
	int *a;
	a = new int[10];

	delete []a;
}
```
This code will result in the `[memleak.cpp:11]: (error) Memory leak: a` error being cleared.

##More Memory Leaks
```
void leakseverywhere(void)
{
	float *a = malloc(sizeof(float) * 45);
}
 
int main(void)
{
	leakseverywhere();
}
```

cppcheck returns:
```
$ cppcheck leaky.cpp
Checking leaky.cpp...
[leaky.cpp:14]: (error) Memory leak: a
```
####Why is there memory vegetable?!?
The memory leek occurs when pointer 'a' goes out of scope.


Bugs that cppcheck does not find
====================================
<a name="styleuse"></a>
##Unused function return value
```
#include<iostream>

using namespace std;

int TestReturn(int &x, int &y)
{
    x = 10;
    y = 20;
    return x * y;
}

int main()
{
    int a = 4
    int b = 2
    cout << b << " " << a << endl;
    TestReturn(a,b);
    cout << b << " " << a << endl;
}
```

cppcheck returns:
```
$ cppcheck Sneakycode.cpp
Checking Sneakycode.cpp...
$
```
####Why didn't it catch the bug?
So far cppcheck does not check for these stylistic bugs.
If you run this code the variables a and b change but what happens to the return statement in the TestReturn function? 
The return statement is essentially useless as it is discarded.
This is what we call an unused function return value.
Cppcheck does not find these bugs because it's a stylistic issue.
If we wanted to make a function that just changed the variable names, we would've just used a void function. 
Cppcheck focuses on the bugs that matter and not stylistic issues.
Using another static debugger would be useful here.

<a name="overflowing"></a>
##Overflow
```
#include<iostream>
using namespace std;
int main()
{
	int i = 2147483647;
	for (int y = i;y > 0;y++)
	{
		cout << "Hello World!";
	}
return 0;
}
```

cppcheck returns:
```
$ cppcheck overflow.cpp
Checking overflow.cpp...
$
```
####Seems normal to me!
One other bug that cppcheck does not check for is overflow.
If we run this code, it would only print out "Hello World!" once.
Why does this happen?
It's because when you add 1 to the max value of a 32 bit integer it overflows.
The integer y would become -2,147,483,648 after adding 1 to y.
This stops the for loop because of the condition that y must be greater than 0. 
Cppcheck did not account for this bug which could be potentially disastrous to anyone's code.
Using the visual studio static debugger [PVS-Studio](http://www.viva64.com/en/pvs-studio/) could help here. 

##Out of bounds on arrays in a function
```
#include<iostream>
using namespace std;
void f(char c)
{
        char *p = new char[10];
        p[c] = 42;
 
        delete []p;
}
int main()
{
        f(100);
}
```

cppcheck returns:
```
$ cppcheck TrickyArray.cpp
Checking TrickyArray.cpp...
$
```
####But didn't you say it checked array bounds?
Yes, it does check array bounds ,but not if its index is passed in through an argument. Currently, cppcheck does not check functions with respect of the parameter.
Cppcheck checks the body of the code but does not evaluate the whole function with the argument included. Thus, it does not give us a message about it being out of bounds.
Remember, one of the goals of cppcheck is to have little to no false positives. This is an example where cppcheck fails where other static debugger succeed.         


##Limits of cppcheck

Some limits of cppcheck include user ignorance and lack of knowledge.
Ok, joking aside, the use of cppcheck is to limit the amount of false positive errors given by other compilers and checkers.
What this means is with general usage, cppcheck will not check much but what it does check, it checks extremely well.
Similar to a crafting NPC in a game, cppcheck will tell you only what it can tell you for sure.
Given the right ingredients, or in cppcheck's case, configurations and flags, it will give you errors that are almost guaranteed to be errors.

cppcheck works in a way where it trues to avoid false positives so many of the bugs listed will be actual bugs.
this being said, there will be many things that cppcheck will not catch such as [stylistic errors](#styleuse), syntax, and [runtime](#overflowing) bugs.

*tl;dr: cppcheck is good at what it does, but use a variety of tools to fully debug your programs.*              

