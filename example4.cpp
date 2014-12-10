int foo()
{
	char arr[10];
	// cppcheck-suppress arrayIndexOutOfBounds	
	arr[15] = 1;

}

