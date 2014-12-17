/*One way to prevent a certain error is by using inline suppression. By 
following the format of `// cppcheck-suppress <ERROR:ID>`, cppcheck will 
recognize this, and will not print out the error. To turn on inline 
suppression, run the command `cppcheck --inline-suppr <FILENAME>`

One can also suppress the error in the command line in the format of 
`cppcheck --suppress=<ERROR:ID> <FILENAME>`*/

/*If you don't know what the error is called when you want to suppress it, you can run the command `cppcheck --xml <FILENAME>` Look for "error id = <ERROR>" for the id of the error. Following the same format as the example, you can suppressthat specific error.*/

int foo()
{
	char arr[10];
	// cppcheck-suppress arrayIndexOutOfBounds	
	arr[15] = 1;

}

###Why?
This allows you to focus on targeted errors that you are looking for. Perhaps you already know the error is there, but because you will use it, there is no need to fix the error. It will also help keep the noise down when debugging the code.
