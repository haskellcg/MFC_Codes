// MFCExp4View.cpp : CMFCExp4View 类的实现
//

#include "stdafx.h"
#include "MFCExp4.h"
#include "StudentLinkTB.h"
#include "MyDialogInput.h"

#include "MFCExp4Doc.h"
#include "MFCExp4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp4View

IMPLEMENT_DYNCREATE(CMFCExp4View, CView)

BEGIN_MESSAGE_MAP(CMFCExp4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_NEWSTUDENT, &CMFCExp4View::OnNewstudent)
	ON_COMMAND(ID_LOAD, &CMFCExp4View::OnLoad)
	ON_COMMAND(ID_STORE, &CMFCExp4View::OnStore)
	ON_COMMAND(ID_PREV, &CMFCExp4View::OnPrev)
	ON_COMMAND(ID_NEXT, &CMFCExp4View::OnNext)
	ON_COMMAND(ID_START, &CMFCExp4View::OnStart)
	ON_COMMAND(ID_END, &CMFCExp4View::OnEnd)
	ON_COMMAND(ID_RED, &CMFCExp4View::OnRed)
	ON_COMMAND(ID_GREEN, &CMFCExp4View::OnGreen)
	ON_COMMAND(ID_BLUE, &CMFCExp4View::OnBlue)
	ON_COMMAND(ID_MORE, &CMFCExp4View::OnMore)
END_MESSAGE_MAP()

// CMFCExp4View 构造/析构

CMFCExp4View::CMFCExp4View()
{
	// TODO: 在此处添加构造代码

}

CMFCExp4View::~CMFCExp4View()
{
}

BOOL CMFCExp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExp4View 绘制

void CMFCExp4View::OnDraw(CDC* pDC)
{
	CMFCExp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	StudentNode temp;
	POSITION pos;
	pos=pDoc->position;

	if(pos!=NULL)
	{
		temp=pDoc->stulink.GetAt(pos);

		pDC->SetTextColor(pDoc->color);

		pDC->TextOutW(100,50,temp.name);
		pDC->TextOutW(100,70,temp.stunum);

		char *msg=new char[20];


		sprintf(msg,"%lf",temp.age);
		CString string(msg);
		pDC->TextOutW(100,90,string);

		sprintf(msg,"%lf",temp.English);
		CString string1(msg);
		pDC->TextOutW(100,110,string1);

		sprintf(msg,"%lf",temp.Chinese);
		CString string2(msg);
		pDC->TextOutW(100,130,string2);

		sprintf(msg,"%lf",temp.Math);
		CString string3(msg);
		pDC->TextOutW(100,150,string3);

		sprintf(msg,"%lf",temp.CLPG);
		CString string4(msg);
		pDC->TextOutW(100,170,string4);

		sprintf(msg,"%lf",temp.everage);
		CString string5(msg);
		pDC->TextOutW(100,190,string5);

		delete []msg;
	}

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExp4View 打印

BOOL CMFCExp4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExp4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExp4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExp4View 诊断

#ifdef _DEBUG
void CMFCExp4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExp4Doc* CMFCExp4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExp4Doc)));
	return (CMFCExp4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExp4View 消息处理程序

void CMFCExp4View::OnNewstudent()
{
	// TODO: 在此添加命令处理程序代码
	MyDialogInput dlgInput;
	int retn=dlgInput.DoModal();

	if(retn==IDOK)
	{
		StudentNode temp;
		temp.SetStudentNode(dlgInput.m_Name_In,dlgInput.m_Age_In,dlgInput.m_Stunum_In,
							dlgInput.m_English_In,dlgInput.m_Chinese_In,dlgInput.m_Math_In,
							dlgInput.m_CLPG_In);
		CMFCExp4Doc* pDoc=GetDocument();
		pDoc->stulink.AddTail(temp);
		pDoc->position=pDoc->stulink.GetTailPosition();
	}

	Invalidate(true);

}

void CMFCExp4View::OnLoad()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	CFileDialog fileDlg(true,0,0,4|2,
						_T("文本文件 (*.txt)|*.txt|All Files (*.*)|*.*||"));
	int retn=fileDlg.DoModal();
	if(retn==IDOK)
	{
		CString fileName;
		fileName=fileDlg.GetFileName();
		AfxMessageBox(fileName);
		CStdioFile stdfile;
		stdfile.Open(fileName,CFile::modeRead|CFile::typeText);

		StudentNode temp;
		CString string;
		while(1)
		{
			if(stdfile.ReadString(string))
			{
				temp.name=string;

				stdfile.ReadString(string);
				temp.stunum=string;

				stdfile.ReadString(string);
				temp.age=_wtoi(string);

				stdfile.ReadString(string);
				temp.English=_wtof(string);

				stdfile.ReadString(string);
				temp.Chinese=_wtof(string);

				stdfile.ReadString(string);
				temp.Math=_wtof(string);

				stdfile.ReadString(string);
				temp.CLPG=_wtof(string);

				stdfile.ReadString(string);
				temp.everage=_wtof(string);

				pDoc->stulink.AddTail(temp);
				pDoc->position=pDoc->stulink.GetHeadPosition();
			}
			else
				break;
		}

		stdfile.Close();

		AfxMessageBox(_T("载入成功！"));

		Invalidate(true);
	}
}

void CMFCExp4View::OnStore()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	CFileDialog fileDlg(false,_T(".txt"),_T("*.txt"),4|2,_T("文本文件 (*.txt)|*.txt|数据库文件 (*.db)|*.db||"));
	int retn=fileDlg.DoModal();
	if(retn==IDOK)
	{
		CString fileName;
		fileName=fileDlg.GetFileName();
		CStdioFile stdfile;
		stdfile.Open(fileName,CFile::modeWrite|CFile::modeCreate|CFile::typeText);

		POSITION pos;
		pos=pDoc->stulink.GetHeadPosition();
		CString strline;
		StudentNode temp;

		while(pos)
		{
			temp=pDoc->stulink.GetNext(pos);
			strline.Format(_T("%s\n %s\n %d\n %lf\n %lf\n %lf\n %lf\n %lf\n"),temp.name,
							temp.stunum,temp.age,temp.English,temp.Chinese,temp.Math,
							temp.CLPG,temp.everage);
			stdfile.WriteString(strline);
			
		}

		stdfile.Close();

		AfxMessageBox(_T("存储成功！"));

	}
}

void CMFCExp4View::OnPrev()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	if(!pDoc->position)
		AfxMessageBox(_T("已经没有了!"));
	else
	{
			POSITION temp=pDoc->position;
			pDoc->stulink.GetPrev(pDoc->position);
			if(pDoc->position)
					Invalidate(true);
			else
			{
				pDoc->position=temp;
				AfxMessageBox(_T("已经没有了!"));
				Invalidate(true);

			}
				
	}
}

void CMFCExp4View::OnNext()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	if(!pDoc->position)
		AfxMessageBox(_T("已经没有了!"));
	else{
			POSITION temp=pDoc->position;
			pDoc->stulink.GetNext(pDoc->position);
			if(pDoc->position)
				Invalidate(true);
			else
			{
				pDoc->position=temp;
				AfxMessageBox(_T("已经没有了!"));
				Invalidate(true);

			}
				
		}
}


void CMFCExp4View::OnStart()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	pDoc->position=pDoc->stulink.GetHeadPosition();
	if(pDoc->position)
			Invalidate(true);
	else
		AfxMessageBox(_T("已经没有了!"));

}

void CMFCExp4View::OnEnd()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	pDoc->position=pDoc->stulink.GetTailPosition();
	if(pDoc->position)
			Invalidate(true);
	else
		AfxMessageBox(_T("已经没有了!"));

}

void CMFCExp4View::OnRed()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	pDoc->color=RGB(255,0,0);
	Invalidate(true);
}

void CMFCExp4View::OnGreen()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	pDoc->color=RGB(0,255,0);
	Invalidate(true);
}

void CMFCExp4View::OnBlue()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();
	pDoc->color=RGB(0,0,255);
	Invalidate(true);
}


void CMFCExp4View::OnMore()
{
	// TODO: 在此添加命令处理程序代码
	CMFCExp4Doc *pDoc=GetDocument();

	CColorDialog colorDlg;
	int retn=colorDlg.DoModal();
	if(retn==IDOK)
	{
		pDoc->color=colorDlg.GetColor();
		Invalidate(true);
	}
	

}
