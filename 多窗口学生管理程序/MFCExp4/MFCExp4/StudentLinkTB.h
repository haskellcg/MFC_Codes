#ifndef STUDENTLINKTB_H_INCLUDED
#define STUDENTLINKTB_H_INCLUDED

#include <afxtempl.h>
#include "stdafx.h"

struct StudentNode
{
	CString name;
	int		age;
	CString stunum;

	double English;
	double Math;
	double Chinese;
	double CLPG;

	double everage;

	StudentNode()
	{
		name="";
		stunum="";

		age=0;

		English=Math=Chinese=everage=CLPG=0;
	}

	void SetStudentNode(CString _name,int _age,CString _stunum,
						double _English,double _Chinese,double _Math,
						double _CLPG)
	{
		name=_name;
		age=_age;
		stunum=_stunum;
		English=_English;
		Math=_Math;
		Chinese=_Chinese;
		CLPG=_CLPG;
		everage=(English+Math+Chinese+CLPG)/4;
	}

	bool operator==(StudentNode stuno)
	{
		if(name!=stuno.name || age!=stuno.age || stunum!=stuno.stunum ||
			English!=stuno.English || Math!=stuno.Math || Chinese!=stuno.Chinese
			|| CLPG!=stuno.CLPG || everage!=stuno.everage)
			return false;
		else
			return true;
	}

	StudentNode& operator=(const StudentNode& stunode)
	{
		if(&stunode==this) return *this;
		else
		{
			name=stunode.name;
			stunum=stunode.stunum;
			age=stunode.age;

			English=stunode.English;
			Math=stunode.Math;
			Chinese=stunode.Chinese;
			CLPG=stunode.CLPG;

			everage=stunode.everage;

			return *this;

		}
	}
};

class StudentLinkTB
{
	protected:
			CList<StudentNode,StudentNode&> Stulink;
	public:	
			StudentLinkTB(INT_PTR nBlockSize=10);
			//StudentLinkTB(const StudentLinkTB& stulink);
			~StudentLinkTB();
		


			const StudentNode& GetHead() const;
			StudentNode& GetHead();
			const StudentNode& GetTail() const;
			StudentNode& GetTail();
           POSITION AddHead(StudentNode stunode);
			void AddHead(StudentLinkTB *stulink);
			POSITION AddTail(StudentNode stunode);
			void AddTail(StudentLinkTB *stulink);
			void RemoveAll();
			StudentNode RemoveHead();
			StudentNode RemoveTail();
			POSITION GetHeadPosition() const;
			POSITION GetTailPosition() const;
			const StudentNode& GetNext(POSITION& rPosition) const;
			StudentNode& GetNext(POSITION& rPosition);
			const StudentNode& GetPrev(POSITION& rPosition) const;
			StudentNode& GetPrev(POSITION& rPosition);
			StudentNode& GetAt(POSITION Position);
			const StudentNode& GetAt(POSITION Position) const;
			void RemoveAt(POSITION Position);
			void SetAt(POSITION pos,StudentNode stunode);
			POSITION InsertAfter(POSITION Position,StudentNode stunode);
			POSITION InsertBefore(POSITION Position,StudentNode stunode);

			//POSITION Find(StudentNode  & stunode,POSITION startAfter=0) const;
			POSITION FindIndex(INT_PTR nIndex) const;
			INT_PTR GetCount() const;
			INT_PTR GetSize() const;
			bool IsEmpty() const;

			const StudentNode* FindByName(CString _name) const;
			StudentNode* FindByName(CString _name);
			const StudentNode* FindByStunum(CString _stunum) const;
			StudentNode* FindByStunum(CString _stunum);
};

#endif