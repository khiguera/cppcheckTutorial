//A simple example of cppcheck finding a bug that would normally be found 
//after compiling and running the executable.
int foo()
{
	char arr[10];
	
	arr[15] = 1;

}



