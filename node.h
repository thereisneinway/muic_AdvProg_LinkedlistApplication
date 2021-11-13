struct Node
{
    int id;
	  string name; 
    Node *next;
    Node *previous;
};

typedef struct Node LLnode;
typedef LLnode *LLPtr;

void insert_node( LLPtr &sPtr,int,string);
void print_LL( LLPtr &sPtr );
void delete_LL( LLPtr &sPtr );

void insert_node( LLPtr &sPtr, int id, string name )
{ 
   LLPtr newPtr;
   LLPtr currentPtr;
   LLPtr previousPtr; 

   newPtr =new LLnode;

   if ( newPtr != NULL ) {
      newPtr->id = id;
      newPtr->name = name;
      newPtr->next = NULL;
      newPtr->previous = NULL;
      
      previousPtr = NULL;
      currentPtr = sPtr;

      while ( currentPtr != NULL && id > currentPtr->id ){//Sorting by ID
         previousPtr = currentPtr;          
         currentPtr = currentPtr->next; 
      } 


      if ( previousPtr == NULL ) { 
         newPtr->next = sPtr;
         newPtr->previous = NULL;
         if(currentPtr) currentPtr->previous = newPtr;
         if(sPtr) sPtr->previous=newPtr;//IDK why this is here it's duplicated
         sPtr = newPtr;
      }

      else {
        previousPtr->next = newPtr;
        newPtr->previous= previousPtr;
        newPtr->next = currentPtr;
        if(currentPtr) currentPtr->previous = newPtr;
      }
   }
   else {
      cout<<" Can't inserted, no memory available, please close Google Chrome"<<endl;
   }
}

void print_LL( LLPtr &sPtr ){
  LLPtr nextPtr;
  nextPtr = sPtr;
  while(nextPtr){
    cout<<"ID: "<<nextPtr->id<<" Name: "<<nextPtr->name<<endl;
    nextPtr = nextPtr->next;
  }
}
void delete_LL( LLPtr &sPtr ){
  LLPtr currentPtr;
  LLPtr tempPtr;
  currentPtr = sPtr;
  while(currentPtr){
    tempPtr = currentPtr->next;
    delete currentPtr;
    currentPtr = tempPtr;
  }
  cout<<"LL deleted"<<endl;
}