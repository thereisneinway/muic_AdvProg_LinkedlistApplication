#include <iostream>
#include <string.h>
using namespace std;
#include "node.h"

int main(int argc, char **argv){
		LLPtr head = NULL;
 		//type in format: id[1] name[1] id[2] name[2].... id[n] name[n]
		for(int i=1;i<argc;i+=2) {
			insert_node(head,atoi(argv[i]),argv[i+1]);
      }
    cout<<"HERE IS THE LIST:"<<endl;
	 	print_LL(head);
    delete_LL(head);
    cout<<"HERE IS THE LIST AFTER DELETE LL:"<<endl;
    print_LL(head);
  return 0;
}

