#include <stdio.h>

int main() {
	for (int i = 0; i < 3; i++){
		fork();
		sleep(5);
	}
	return 0;
}
/*
OUTPUT:
bash─┬─ex2───ex2
     └─pstree

bash─┬─ex2─┬─ex2───ex2
     │     └─ex2
     └─pstree

bash─┬─ex2─┬─ex2─┬─ex2───ex2
     │     │     └─ex2
     │     ├─ex2───ex2
     │     └─ex2
     └─pstree

Explanation:
So, we have 8(2^3) processes after 3 loop iterations executed.
*/
