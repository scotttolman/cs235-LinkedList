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
	Node <T> * pNew = new Node <T> (t);

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
Node <T> * copy(/*const*/ Node <T> * pSource) throw (const char*)
{
	Node <T> * pDestination = new Node <T>(pSource->data);
	Node <T> * pSrc = pSource;
	Node <T> * pDes = pDestination;

	for (pSrc = pSrc->pNext; pSrc/*->pNext*/ != NULL; pSrc = pSrc->pNext)
	{
		pDes = insert(pDes, pSrc->data, true);
	}
	return pDestination;
}

/******************************************************
* FREEDATA
* deletes all the nodes in a linked list
******************************************************/
template <class T>
void freeData(Node <T> * pHead)
{
	Node <T> * pDelete;
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
	Node <T> * p;
	for (p = pHead; p != NULL; p = p->pNext)
	{
		if (p->data == t)
			return p;
	}
	return NULL;
}

/******************************************************
* REMOVE
* deletes a single node from a linked list
******************************************************/
template <class T>
Node <T> * remove(const Node <T> * pRemove)
{
	Node <T> * pReturn = NULL;
	if (NULL == pRemove)
		return pReturn;

	if (pRemove->pPrev)
		pRemove->pPrev->pNext = pRemove->pNext;
	if (pRemove->pNext)
		pRemove->pNext->pPrev = pRemove->pPrev;

	if (pRemove->pPrev)
		pReturn = pRemove->pPrev;
	else
		pReturn = pRemove->pNext;

	delete pRemove;
	return pReturn;
}

/*******************************************************
* INSERTION OPERATOR <<
* displays the contents of a given linked list
********************************************************
template <class T>
ostream & operator << (ostream & out, const Node <T> * rhs)
{
	Node <T> * p = rhs;
	while (p != NULL)
	{
		cout << p->data << ", ";
		p = p->pNext;
	}
}*/

#endif // !Node_H
