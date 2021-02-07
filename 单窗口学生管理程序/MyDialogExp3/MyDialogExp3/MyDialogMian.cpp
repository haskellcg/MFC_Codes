// MyDialogMian.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDialogExp3.h"
#include "MyDialogMian.h"
#include "MyDialogIn.h"
#include "MyDialogFind.h"


// MyDialogMian 对话框

IMPLEMENT_DYNAMIC(MyDialogMian, CDialog)

MyDialogMian::MyDialogMian(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialogMian::IDD, pParent)
	, m_Name_Out(_T(""))
	, m_Stunum_Out(_T(""))
	, m_Age_Out(0)
	, m_English_Out(0)
	, m_Chinese_Out(0)
	, m_Math_Out(0)
	, m_CLPG_Out(0)
	, m_Everage_Out(0)
	, position(NULL)
{
	hIcon=AfxGetApp()->LoadIconW(IDI_ICON_MAIN);
}

MyDialogMian::~MyDialogMian()
{
}

BOOL MyDialogMian::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(hIcon,true);
	SetIcon(hIcon,false);
	return true;
}


void MyDialogMian::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OUT_NAME, m_Name_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_AGE, m_Age_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_ENGLISH, m_English_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_CHINESE, m_Chinese_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_MATH, m_Math_Out);
	DDX_Text(pDX, IDC_EDIT1_OUT_CLPG, m_CLPG_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_STUNUM, m_Stunum_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_AGE, m_Age_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_ENGLISH, m_English_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_CHINESE, m_Chinese_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_MATH, m_Math_Out);
	DDX_Text(pDX, IDC_EDIT1_OUT_CLPG, m_CLPG_Out);
	DDX_Text(pDX, IDC_EDIT_OUT_EVERAGE, m_Everage_Out);
}


BEGIN_MESSAGE_MAP(MyDialogMian, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_IN, &MyDialogMian::OnBnClickedButtonIn)
	ON_BN_CLICKED(IDC_BUTTON_WRITE, &MyDialogMian::OnBnClickedButtonWrite)
	ON_BN_CLICKED(IDC_BUTTON_READ, &MyDialogMian::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_HEAD, &MyDialogMian::OnBnClickedHead)
	ON_BN_CLICKED(IDC_TAIL, &MyDialogMian::OnBnClickedTail)
	ON_BN_CLICKED(IDC_NEXT, &MyDialogMian::OnBnClickedNext)
	ON_BN_CLICKED(IDC_PREV, &MyDialogMian::OnBnClickedPrev)
	ON_BN_CLICKED(IDC_BUTTON_FIND, &MyDialogMian::OnBnClickedButtonFind)
END_MESSAGE_MAP()


// MyDialogMian 消息处理程序

void MyDialogMian::OnBnClickedButtonIn()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDialogIn inDlg;
	int retn = inDlg.DoModal();
	if(retn == IDOK)
	{
		m_Name_Out=inDlg.m_Name_In;
		m_Stunum_Out=inDlg.m_Stunum_In;

		m_Age_Out=inDlg.m_Age_In;

		m_English_Out=inDlg.m_English_In;
		m_Chinese_Out=inDlg.m_Chinese_In;
		m_Math_Out=inDlg.m_Math_In;
		m_CLPG_Out=inDlg.m_CLPG_In;
		
		m_Everage_Out=(m_Math_Out + m_English_Out + m_Chinese_Out + m_CLPG_Out)/4;


		UpdateData(false);

		StudentNode temp;
		temp.SetStudentNode(m_Name_Out,m_Age_Out,m_Stunum_Out,m_English_Out,
							m_Chinese_Out,m_Math_Out,m_CLPG_Out);
		stulink.AddTail(temp);
		position=stulink.GetTailPosition();
	}

}

void MyDialogMian::OnBnClickedButtonWrite()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fileDlg(false);
	int retn=fileDlg.DoModal();
	if(retn==IDOK)
	{
		CString fileName;
		fileName=fileDlg.GetPathName();

		CStdioFile stdfile;
		stdfile.Open(fileName,CFile::modeCreate| CFile::modeWrite | CFile::typeText);

		POSITION pos;
		StudentNode temp;
		CString     temps;
		pos=stulink.GetHeadPosition();
		while(pos)
		{
			temp=stulink.GetNext(pos);
			temps.Format(_T("%s\n%s\n%d\n%lf\n%lf\n%lf\n%lf\n%lf\n"),
						 temp.name,temp.stunum,temp.age,
						 temp.English,temp.Chinese,temp.Math,
						 temp.CLPG,temp.everage);
			stdfile.WriteString(temps);
		}

		stdfile.Close();
		AfxMessageBox(_T("恭喜你！存储成功！"));
	}

	else
	{
		AfxMessageBox(_T("没有存储数据!"));
	}
}

void MyDialogMian::OnBnClickedButtonRead()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fileDlg(true);
	int retn=fileDlg.DoModal();
	if(retn==IDOK)
	{
		stulink.RemoveAll();
		CString fileName;
		fileName=fileDlg.GetPathName();

		CStdioFile stdfile;
		stdfile.Open(fileName,CFile::modeRead | CFile::typeText);

		CString strline;
		while(1)
		{
			if(stdfile.ReadString(strline))
			{
				StudentNode temp;
				
				temp.name=strline;

				stdfile.ReadString(strline);
				temp.stunum=strline;

				stdfile.ReadString(strline);
				temp.age=_wtoi(strline);

				stdfile.ReadString(strline);
				temp.English=_wtof(strline);

				stdfile.ReadString(strline);
				temp.Chinese=_wtof(strline);

				stdfile.ReadString(strline);
				temp.Math=_wtof(strline);

				stdfile.ReadString(strline);
				temp.CLPG=_wtof(strline);

				stdfile.ReadString(strline);
				temp.everage=_wtof(strline);

				stulink.AddTail(temp);

			}

			else
				break;
		}
		position=stulink.GetHeadPosition();

		StudentNode node;
		node=stulink.GetHead();
		m_Name_Out=node.name;
		m_Stunum_Out=node.stunum;
		m_Age_Out=node.age;
		m_English_Out=node.English;
		m_Chinese_Out=node.Chinese;
		m_Math_Out=node.Math;
		m_CLPG_Out=node.CLPG;
		m_Everage_Out=node.everage;
		UpdateData(false);

		stdfile.Close();
		AfxMessageBox(_T("恭喜你！读取成功！"));
	}
	else
	{
		AfxMessageBox(_T("没有读取数据!"));
	}

}

void MyDialogMian::OnBnClickedHead()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos=position;
	position=stulink.GetHeadPosition();
	if(position)
	{
		StudentNode node;
		node=stulink.GetHead();

		m_Name_Out=node.name;
		m_Stunum_Out=node.stunum;
		m_Age_Out=node.age;
		m_English_Out=node.English;
		m_Chinese_Out=node.Chinese;
		m_Math_Out=node.Math;
		m_CLPG_Out=node.CLPG;
		m_Everage_Out=node.everage;

		UpdateData(false);
	}
	else
	{
		AfxMessageBox(_T("注意！没有了！"));
		position=pos;
	}

}

void MyDialogMian::OnBnClickedTail()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos=position;
	position=stulink.GetTailPosition();
	if(position)
	{
		StudentNode node;
		node=stulink.GetTail();

		m_Name_Out=node.name;
		m_Stunum_Out=node.stunum;
		m_Age_Out=node.age;
		m_English_Out=node.English;
		m_Chinese_Out=node.Chinese;
		m_Math_Out=node.Math;
		m_CLPG_Out=node.CLPG;
		m_Everage_Out=node.everage;

		UpdateData(false);
	}
	else
	{
		AfxMessageBox(_T("注意！没有了！"));
		position=pos;
	}

}

void MyDialogMian::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!position)
	{
		AfxMessageBox(_T("注意！没有了！"));
	}
	else
	{
		StudentNode node;
		POSITION pos=position;
		stulink.GetNext(position);
		if(position)
		{
			node=stulink.GetAt(position);
			
			m_Name_Out=node.name;
			m_Stunum_Out=node.stunum;
			m_Age_Out=node.age;
			m_English_Out=node.English;
			m_Chinese_Out=node.Chinese;
			m_Math_Out=node.Math;
			m_CLPG_Out=node.CLPG;
			m_Everage_Out=node.everage;

			UpdateData(false);


		}
		else
		{
			AfxMessageBox(_T("注意！没有了！"));
			position=pos;
		}

	}
}

void MyDialogMian::OnBnClickedPrev()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!position)
	{
		AfxMessageBox(_T("注意！没有了！"));
	}
	else
	{
		StudentNode node;
		POSITION pos=position;
		stulink.GetPrev(position);
		if(position)
		{
			node=stulink.GetAt(position);
			m_Name_Out=node.name;
			m_Stunum_Out=node.stunum;
			m_Age_Out=node.age;
			m_English_Out=node.English;
			m_Chinese_Out=node.Chinese;
			m_Math_Out=node.Math;
			m_CLPG_Out=node.CLPG;
			m_Everage_Out=node.everage;

			UpdateData(false);


		}
		else
		{
			position=pos;
			AfxMessageBox(_T("注意！没有了！"));
		}

	}
}

void MyDialogMian::OnBnClickedButtonFind()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDialogFind findDlg;
	int retn=findDlg.DoModal();
	if(retn==IDOK)
	{
		int flag=findDlg.flag;
		if(flag==0)
		{
			CString tempName=findDlg.m_Name_Find;
			StudentNode *tempNode;
			POSITION pos=position;

			tempNode=stulink.FindByNameReturnNode(tempName);
			position=stulink.FindByNameReturnPosition(tempName);
			if(position)
			{
				m_Name_Out=tempNode->name;
				m_Stunum_Out=tempNode->stunum;
				m_Age_Out=tempNode->age;
				m_English_Out=tempNode->English;
				m_Chinese_Out=tempNode->Chinese;
				m_Math_Out=tempNode->Math;
				m_CLPG_Out=tempNode->CLPG;
				m_Everage_Out=tempNode->everage;

				UpdateData(false);
			}
			else
			{
				AfxMessageBox(_T("对不起，找不到您输入的名字的对应学生，请确认！"));
				position=pos;
			}
			
		}
		else if(flag==1)
			{
				CString tempStunum=findDlg.m_Stunum_Find;
				StudentNode *tempNode;
				POSITION pos=position;

				tempNode=stulink.FindByStunumReturnNode(tempStunum);
				position=stulink.FindByStunumReturnPosition(tempStunum);
				if(position)
				{
					m_Name_Out=tempNode->name;
					m_Stunum_Out=tempNode->stunum;
					m_Age_Out=tempNode->age;
					m_English_Out=tempNode->English;
					m_Chinese_Out=tempNode->Chinese;
					m_Math_Out=tempNode->Math;
					m_CLPG_Out=tempNode->CLPG;
					m_Everage_Out=tempNode->everage;

					UpdateData(false);
				}
				else
				{
					AfxMessageBox(_T("对不起，找不到您输入的学号的对应学生，请确认！"));
					position=pos;
				}
			
			}
			else
			{
				AfxMessageBox(_T("没有选择！"));
			}
	}
}
