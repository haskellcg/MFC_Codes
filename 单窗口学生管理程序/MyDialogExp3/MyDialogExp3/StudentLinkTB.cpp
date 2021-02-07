#include "stdafx.h"
#include "StudentLinkTB.h"
#include <iostream>
using namespace std;

StudentLinkTB::StudentLinkTB(INT_PTR nBlockSize):Stulink(nBlockSize)
{
}



StudentLinkTB::~StudentLinkTB()
{
}

const StudentNode& StudentLinkTB::GetHead() const
{
	return Stulink.GetHead();
}

StudentNode& StudentLinkTB::GetHead()
{
	return Stulink.GetHead();
}

const StudentNode& StudentLinkTB::GetTail() const
{
	return Stulink.GetTail();
}

StudentNode& StudentLinkTB::GetTail()
{
	return Stulink.GetTail();
}

POSITION StudentLinkTB::AddHead(StudentNode stunode)
{
	return Stulink.AddHead(stunode);
}

void StudentLinkTB::AddHead(StudentLinkTB *stulink)
{
	Stulink.AddHead(&stulink->Stulink);
}

POSITION StudentLinkTB::AddTail(StudentNode stunode)
{
	return Stulink.AddTail(stunode);
}

void StudentLinkTB::AddTail(StudentLinkTB *stulink)
{
	Stulink.AddTail(&stulink->Stulink);
}

void StudentLinkTB::RemoveAll()
{
	Stulink.RemoveAll();
}

StudentNode StudentLinkTB::RemoveHead()
{
	return Stulink.RemoveHead();
}

StudentNode StudentLinkTB::RemoveTail()
{
	return Stulink.RemoveTail();
}

POSITION StudentLinkTB::GetHeadPosition() const
{
	return Stulink.GetHeadPosition();
}

POSITION StudentLinkTB::GetTailPosition() const
{
	return Stulink.GetTailPosition();
}

const StudentNode& StudentLinkTB::GetNext(POSITION& rPosition) const
{
	return Stulink.GetNext(rPosition);
}

StudentNode& StudentLinkTB::GetNext(POSITION& rPosition)
{
	return Stulink.GetNext(rPosition);
}

const StudentNode& StudentLinkTB::GetPrev(POSITION& rPosition) const
{
	return Stulink.GetPrev(rPosition);
}

StudentNode& StudentLinkTB::GetPrev(POSITION& rPosition)
{
	return Stulink.GetPrev(rPosition);
}

const StudentNode& StudentLinkTB::GetAt(POSITION Position) const
{
	return Stulink.GetAt(Position);
}


StudentNode& StudentLinkTB::GetAt(POSITION Position)
{
	return Stulink.GetAt(Position);
}

void StudentLinkTB::RemoveAt(POSITION Position)
{
	Stulink.RemoveAt(Position);
}

void StudentLinkTB::SetAt(POSITION pos,StudentNode stunode)
{
	Stulink.SetAt(pos,stunode);
}

POSITION StudentLinkTB::InsertAfter(POSITION Position,StudentNode stunode)
{
	return Stulink.InsertAfter(Position,stunode);
}

POSITION StudentLinkTB::InsertBefore(POSITION Position,StudentNode stunode)
{
	return Stulink.InsertBefore(Position,stunode);
}




POSITION StudentLinkTB::FindIndex(INT_PTR nIndex) const
{
	return Stulink.FindIndex(nIndex);
}

INT_PTR StudentLinkTB::GetCount() const
{
	return Stulink.GetCount();
}

INT_PTR StudentLinkTB::GetSize() const
{
	return Stulink.GetSize();
}

bool StudentLinkTB::IsEmpty() const
{
	return (bool)Stulink.IsEmpty();
}

const StudentNode* StudentLinkTB::FindByNameReturnNode(CString _name) const
{
	POSITION pos;
	pos=Stulink.GetHeadPosition();
    if(pos==NULL)
	{
		return NULL;
	}
	else 
	{
		StudentNode temp;
		POSITION temppos=pos;
		temp=Stulink.GetNext(pos);
		while(pos && temp.name!=_name)
		{
			temppos=pos;
			temp=Stulink.GetNext(pos);
		}

		if(pos==NULL)
		{
			if(temp.name!=_name)
				return NULL;
			else
				return &Stulink.GetAt(temppos);
		}
		else
			return &Stulink.GetAt(temppos);
	}
}

StudentNode* StudentLinkTB::FindByNameReturnNode(CString _name)
{
	POSITION pos;
	pos=Stulink.GetHeadPosition();
    if(pos==NULL)
	{
		return NULL;
	}
	else 
	{
		StudentNode temp;
		POSITION temppos=pos;
		temp=Stulink.GetNext(pos);
		while(pos && temp.name!=_name)
		{
			temppos=pos;
			temp=Stulink.GetNext(pos);
		}

		if(pos==NULL)
		{
			if(temp.name!=_name)
				return NULL;
			else
				return &Stulink.GetAt(temppos);
		}
		else
			return &Stulink.GetAt(temppos);
	}
}

const POSITION StudentLinkTB::FindByNameReturnPosition(CString _name) const
{
	POSITION pos;
	pos=Stulink.GetHeadPosition();
    if(pos==NULL)
	{
		return NULL;
	}
	else 
	{
		StudentNode temp;
		POSITION temppos=pos;
		temp=Stulink.GetNext(pos);
		while(pos && temp.name!=_name)
		{
			temppos=pos;
			temp=Stulink.GetNext(pos);
		}

		if(pos==NULL)
		{
			if(temp.name!=_name)
				return NULL;
			else
				return temppos;
		}
		else
			return temppos;
	}
}

POSITION StudentLinkTB::FindByNameReturnPosition(CString _name)
{
	POSITION pos;
	pos=Stulink.GetHeadPosition();
    if(pos==NULL)
	{
		return NULL;
	}
	else 
	{
		StudentNode temp;
		POSITION temppos=pos;
		temp=Stulink.GetNext(pos);
		while(pos && temp.name!=_name)
		{
			temppos=pos;
			temp=Stulink.GetNext(pos);
		}

		if(pos==NULL)
		{
			if(temp.name!=_name)
				return NULL;
			else
				return temppos;
		}
		else
			return temppos;
	}
	
}

const StudentNode* StudentLinkTB::FindByStunumReturnNode(CString _stunum) const
{
	POSITION pos;
	pos=Stulink.GetHeadPosition();
    if(pos==NULL)
	{
		return NULL;
	}
	else 
	{
		StudentNode temp;
		POSITION temppos=pos;
		temp=Stulink.GetNext(pos);
		while(pos && temp.stunum!=_stunum)
		{
			temppos=pos;
			temp=Stulink.GetNext(pos);
		}
		if(pos==NULL)
		{
			if(temp.stunum!=_stunum)
				return NULL;
			else
				return &Stulink.GetAt(temppos);
		}
		else
			return &Stulink.GetAt(temppos);

	}
}

StudentNode* StudentLinkTB::FindByStunumReturnNode(CString _stunum)
{
	POSITION pos;
	pos=Stulink.GetHeadPosition();
    if(pos==NULL)
	{
		return NULL;
	}
	else 
	{
		StudentNode temp;
		POSITION temppos=pos;
		temp=Stulink.GetNext(pos);
		while(pos && temp.stunum!=_stunum)
		{
			temppos=pos;
			temp=Stulink.GetNext(pos);
		}
		if(pos==NULL)
		{
			if(temp.stunum!=_stunum)
				return NULL;
			else
				return &Stulink.GetAt(temppos);
		}
		else
			return &Stulink.GetAt(temppos);

	}
}

const POSITION StudentLinkTB::FindByStunumReturnPosition(CString _stunum) const
{
	POSITION pos;
	pos=Stulink.GetHeadPosition();
    if(pos==NULL)
	{
		return NULL;
	}
	else 
	{
		StudentNode temp;
		POSITION temppos=pos;
		temp=Stulink.GetNext(pos);
		while(pos && temp.stunum!=_stunum)
		{
			temppos=pos;
			temp=Stulink.GetNext(pos);
		}
		if(pos==NULL)
		{
			if(temp.stunum!=_stunum)
				return NULL;
			else
				return temppos;
		}
		else
			return temppos;

	}
}

POSITION StudentLinkTB::FindByStunumReturnPosition(CString _stunum)
{
	POSITION pos;
	pos=Stulink.GetHeadPosition();
    if(pos==NULL)
	{
		return NULL;
	}
	else 
	{
		StudentNode temp;
		POSITION temppos=pos;
		temp=Stulink.GetNext(pos);
		while(pos && temp.stunum!=_stunum)
		{
			temppos=pos;
			temp=Stulink.GetNext(pos);
		}
		if(pos==NULL)
		{
			if(temp.stunum!=_stunum)
				return NULL;
			else
				return temppos;
		}
		else
			return temppos;
	}
}
/*
POSITION StudentLinkTB::Find(StudentNode & stunode, POSITION startAfter) const
{
	return Stulink.Find(stunode,startAfter);
}

StudentLinkTB::StudentLinkTB(const StudentLinkTB &stulink)
{

}
*/