// STUploadDoc.h : CSTUploadDoc ��Ľӿ�
//


#pragma once
#include "stockdatalist.h"


class CSTUploadDoc : public CDocument
{
protected: // �������л�����
	CSTUploadDoc();
	DECLARE_DYNCREATE(CSTUploadDoc)

// ����
public:

// ����
protected:
	bool LoadData(CStdioFile& infile);
	

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CSTUploadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	CStockDataList m_DocList;
	CString m_strCurrentFund;
public:

	CStockDataList& GetDocList(void)
	{
		//TODO: insert return statement here
		return m_DocList;
	}

	CString GetCurrentFund(){return m_strCurrentFund;}
	void SetCurrentFund(CString strSet){m_strCurrentFund=strSet;}
	afx_msg void OnDataImport();
	virtual void DeleteContents();
};


