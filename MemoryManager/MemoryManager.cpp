#include <cassert>
#include <iostream>
#include "dlUtils.h"
#include "MemoryManager.h"

MemoryManager::MemoryManager(unsigned int memtotal): memsize(memtotal)
{
   baseptr = new unsigned char[memsize];
   blockdata originalBlock(memsize,true,baseptr);
   firstBlock = new dlNode<blockdata>(originalBlock,NULL,NULL);
}

void MemoryManager::showBlockList() 
{
  printDlList(firstBlock,"->");
}

void MemoryManager::splitBlock(dlNode<blockdata> *p, unsigned int chunksize)
{ // Put your code below
  
  int oldSize = p->info.blocksize;
  p->info.blocksize = chunksize;
  blockdata newBlock(oldSize - chunksize, true, p->info.blockptr + chunksize);
  dlNode<blockdata> *newNode = new dlNode<blockdata>(newBlock, p, p->next);

  if(newNode->next != NULL) 
  {
  	newNode->next->prev = newNode;
  }

  p->next = newNode;
}

unsigned char * MemoryManager::malloc(unsigned int request)
{ // Put your code below
	
	dlNode<blockdata> *temp = firstBlock;	// Assign first node in list to temp variable

	// Iterate through list and check for free memory that meets requested size
	while(temp != NULL)
	{
		
		if(temp->info.blocksize == request && temp->info.free)
		{
			temp->info.free = false;
			return temp->info.blockptr;
		}
			
		else if(temp->info.blocksize > request && temp->info.free)
		{
			splitBlock(temp, request);	// Call split block function to add a new node to the list
			temp->info.free = false;
			return temp->info.blockptr;
		}

		temp = temp->next; 
	}

	return NULL;
}

void MemoryManager::mergeForward(dlNode<blockdata> *p)
{ // Put your code below
	while(p->next->info.free)
	{
		dlNode<blockdata> *temp = p->next;
		int oldSize = temp->info.blocksize;

		p->info.blockptr = p->info.blockptr + oldSize;
		deleteNode(p, temp);
		p = p->next;

	}
}

void MemoryManager::free(unsigned char *ptr2block)
{ // Put your code below
	dlNode<blockdata> *temp = firstBlock;

	while(temp != NULL)
	{
		if(temp->info.blockptr == ptr2block)
		{
			temp->info.free = true;
			break;
		}

		temp = temp->next;
	}

	mergeForward(temp);
}


