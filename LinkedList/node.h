/***********************************************************************
* Header:
*    Node
* Summary:
*    This will contain Node class
* Author
*    Scott Tolman
************************************************************************/

#ifndef Node_H
#define Node_H

//namespace custom
//{
	template <class T>
	class Node
	{
	public:
		T data;
		Node * pNext;
		Node * pPrev;

		Node() : data(NULL), pNext(NULL), pPrev(NULL) {};
		Node(const T & t) : data(t), pNext(NULL), pPrev(NULL) {};
	};

	/******************************************************
	* INSERT
	* inserts a node into the linked list
	******************************************************/
	template <class T>
	Node <T> * insert(Node <T> * pCurrent, const T & t, bool after = false)
	{
		Node pNew = new Node(t);

		if (pCurrent != NULL && after == false)
		{
			pNew->pNext = pCurrent;
			pNew->pPrev = pCurrent->pPrev;
			pCurrent->pPrev = pNew;
			pNew->pPrev->pNext = pNew;
		}
		else if (pCurrent != NULL && after == true)
		{
			pNew->pPrev = pCurrent;
			pNew->pNext = pCurrent->pNext;
			pCurrent->pNext = pNew;
			pNew->pNext->pPrev = pNew;
		}
		//else if ()
		return pNew;
	}

	/****************************************************
	* COPY
	* copies all the nodes from one linked list into a 
	* new linked list
	****************************************************/
	template <class T>
	Node <T> * copy(const Node <T> * pSource) throw (const char*)
	{

	}

	/******************************************************
	* FREEDATA
	* deletes all the nodes in a linked list
	******************************************************/
	template <class T>
	void freeData(Node <T> * pHead)
	{
		Node * pDelete;
		while (pHead != NULL)
		{
			pDelete = pHead;
			pHead = pHead->pNext;
			delete pDelete;
		}
	}

	/******************************************************
	* FIND
	* traverses linked list to find Node, returns Node or NULL
	******************************************************/
	template <class T>
	Node <T> * find(Node <T> * pHead, const T & t)
	{

	}

	/******************************************************
	* REMOVE
	* deletes a single node from a linked list
	******************************************************/
	template <class T>
	Node <T> * remove(const Node <T> * pRemove)
	{

	}

	/*******************************************************
	* INSERTION OPERATOR <<
	* displays the contents of a given linked list
	********************************************************/
	template <class T>
	ostream & operator << (ostream & out, const Node <T> * rhs)
	{

	}
//}

#endif // !Node_H
